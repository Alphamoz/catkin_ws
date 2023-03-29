/****************************************************************/
/*                                                              */
/*          Advanced Navigation Packet Protocol Library         */
/*        ROS Driver, Packet to Published Message Example       */
/*          Copyright 2017, Advanced Navigation Pty Ltd         */
/*                                                              */
/****************************************************************/
/*
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include <tf/tf.h>

#include "rs232/rs232.h"
#include "an_packet_protocol.h"
#include "spatial_packets.h"

// ini msgnya
#include <sensor_msgs/NavSatFix.h>
#include <gb_navigation/Spatial.h>
#include <gb_navigation/Gps.h>
#include <sensor_msgs/TimeReference.h>
#include <sensor_msgs/Imu.h>
#include <auv_msgs/RPY.h>
#include <auv_msgs/NED.h>
#include <geometry_msgs/Twist.h>
#include <diagnostic_msgs/DiagnosticArray.h>



#define RADIANS_TO_DEGREES (180.0/M_PI)

int main(int argc, char *argv[]) {
	// Set up ROS node //
	ros::init(argc, argv, "spatial_node");
	ros::NodeHandle nh;
	ros::NodeHandle pnh("~");

	printf("\nYour Advanced Navigation ROS driver is currently running\nPress Ctrl-C to interrupt\n");

	// Set up the COM port
	std::string com_port;
	int baud_rate;
	std::string imu_frame_id;
	std::string nav_sat_frame_id;
	std::string topic_prefix;

	if (argc >= 3) {
		com_port = std::string(argv[1]);
		baud_rate = atoi(argv[2]);
	}
	else {
		pnh.param("port", com_port, std::string("/dev/ttyACM0"));
		pnh.param("baud_rate", baud_rate, 115200);
	}

	pnh.param("imu_frame_id", imu_frame_id, std::string("imu"));
	pnh.param("nav_sat_frame_id", nav_sat_frame_id, std::string("gps"));
	pnh.param("topic_prefix", topic_prefix, std::string("gb_navigation/spatial"));

	// Initialise Publishers and Topics //
	ros::Publisher spatial_pub=nh.advertise<gb_navigation::Spatial>(topic_prefix,10);
	ros::Publisher gps_pub=nh.advertise<gb_navigation::Gps>(topic_prefix,10);
	ros::Publisher system_status_pub=nh.advertise<diagnostic_msgs::DiagnosticStatus>(topic_prefix + "/SystemStatus",10);
	ros::Publisher filter_status_pub=nh.advertise<diagnostic_msgs::DiagnosticStatus>(topic_prefix + "/FilterStatus",10);

	//initialise Spatial
	//Ned _ned(0.0, 0.0, 0.0);
	bool init_ned = false ;
	gb_navigation::Spatial spatial_msg;

	spatial_msg.header.stamp.sec=0;
	spatial_msg.header.stamp.nsec=0;
	spatial_msg.header.frame_id='0';

	// spatial_msg.NED.north = 0;
	// spatial_msg.NED.east = 0;
	// spatial_msg.NED.depth = 0;

	// spatial_msg.Gps.status.status=0;
	// spatial_msg.Gps.status.service=1; // fixed to GPS
	// spatial_msg.Gps.latitude=0.0;
	// spatial_msg.Gps.longitude=0.0;
	// spatial_msg.Gps.altitude=0.0;
	// spatial_msg.Gps.position_covariance={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	// spatial_msg.Gps.position_covariance_type=2; // fixed to variance on the diagonal

	spatial_msg.Twist.linear.x=0.0;
	spatial_msg.Twist.linear.y=0.0;
	spatial_msg.Twist.linear.z=0.0;
	spatial_msg.Twist.angular.x=0.0;
	spatial_msg.Twist.angular.y=0.0;
	spatial_msg.Twist.angular.z=0.0;

	spatial_msg.Imu.orientation.x=0.0;
	spatial_msg.Imu.orientation.y=0.0;
	spatial_msg.Imu.orientation.z=0.0;
	spatial_msg.Imu.orientation.w=0.0;
	spatial_msg.Imu.orientation_covariance={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	spatial_msg.Imu.angular_velocity.x=0.0;
	spatial_msg.Imu.angular_velocity.y=0.0;
	spatial_msg.Imu.angular_velocity.z=0.0;
	spatial_msg.Imu.angular_velocity_covariance={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}; // fixed
	spatial_msg.Imu.linear_acceleration.x=0.0;
	spatial_msg.Imu.linear_acceleration.y=0.0;
	spatial_msg.Imu.linear_acceleration.z=0.0;
	spatial_msg.Imu.linear_acceleration_covariance={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}; // fixed

	spatial_msg.RPY.roll = 0;
	spatial_msg.RPY.pitch = 0;
	spatial_msg.RPY.yaw = 0;

	diagnostic_msgs::DiagnosticStatus system_status_msg;
	system_status_msg.level = 0; // default OK state
	system_status_msg.name = "System Status";
	system_status_msg.message = "";

	diagnostic_msgs::DiagnosticStatus filter_status_msg;
	filter_status_msg.level = 0; // default OK state
	filter_status_msg.name = "Filter Status";
	filter_status_msg.message = "";

	// get data from com port //
	an_decoder_t an_decoder;
	an_packet_t *an_packet;
	system_state_packet_t system_state_packet;
	euler_orientation_standard_deviation_packet_t euler_orientation_standard_deviation_packet;
	velocity_standard_deviation_packet_t velocity_standard_deviation_packet; 
	//quaternion_orientation_standard_deviation_packet_t quaternion_orientation_standard_deviation_packet;
	int bytes_received;

	if (OpenComport(const_cast<char*>(com_port.c_str()), baud_rate))
	{
		printf("Could not open serial port: %s \n",com_port.c_str());
		exit(EXIT_FAILURE);
	}

	an_decoder_initialise(&an_decoder);

	// Loop continuously, polling for packets
	while (ros::ok())
	{
		ros::spinOnce();
		if ((bytes_received = PollComport(an_decoder_pointer(&an_decoder), an_decoder_size(&an_decoder))) > 0)
		{
			// increment the decode buffer length by the number of bytes received //
			an_decoder_increment(&an_decoder, bytes_received);

			// decode all the packets in the buffer //
			while ((an_packet = an_packet_decode(&an_decoder)) != NULL)
			{
				// system state packet //
				if (an_packet->id == packet_id_system_state)
				{
					if(decode_system_state_packet(&system_state_packet, an_packet) == 0)
					{
						//NavSatFix
						spatial_msg.header.stamp.sec=system_state_packet.unix_time_seconds;
						spatial_msg.header.stamp.nsec=system_state_packet.microseconds*1000;
						spatial_msg.header.frame_id=nav_sat_frame_id;
						// if ((system_state_packet.filter_status.b.gnss_fix_type == 1) ||
						// 	(system_state_packet.filter_status.b.gnss_fix_type == 2))
						// {
						// 	spatial_msg.Gps.status.status=0;
						// }
						// else if ((system_state_packet.filter_status.b.gnss_fix_type == 3) ||
						// 	 (system_state_packet.filter_status.b.gnss_fix_type == 5))
						// {
						// 	spatial_msg.Gps.status.status=1;
						// }
						// else if ((system_state_packet.filter_status.b.gnss_fix_type == 4) ||
						// 	 (system_state_packet.filter_status.b.gnss_fix_type == 6) ||
						// 	 (system_state_packet.filter_status.b.gnss_fix_type == 7))
						// {
						// 	spatial_msg.Gps.status.status=2;
						// }
						// else
						// {
						// 	spatial_msg.Gps.status.status=-1;
						// }
						// spatial_msg.Gps.latitude=system_state_packet.latitude * RADIANS_TO_DEGREES;
						// spatial_msg.Gps.longitude=system_state_packet.longitude * RADIANS_TO_DEGREES;
						// spatial_msg.Gps.altitude=system_state_packet.height;

						// if ( !init_ned )
						// {
						// 	_ned.init(spatial_msg.Gps.latitude , spatial_msg.Gps.longitude, spatial_msg.Gps.altitude);
						// 	init_ned = true ;
						// }

						// double north, east, depth;
                    	// _ned.geodetic2Ned( spatial_msg.Gps.latitude , spatial_msg.Gps.longitude, spatial_msg.Gps.altitude, north, east, depth );
						// spatial_msg.NED.north = north ;
						// spatial_msg.NED.east = east ;
						// spatial_msg.NED.depth = depth ;

						// spatial_msg.Gps.position_covariance={pow(system_state_packet.standard_deviation[1],2), 0.0, 0.0,
						// 	0.0, pow(system_state_packet.standard_deviation[0],2), 0.0,
						// 	0.0, 0.0, pow(system_state_packet.standard_deviation[2],2)};

						// Twist
						spatial_msg.Twist.linear.x=system_state_packet.velocity[0];
						spatial_msg.Twist.linear.y=system_state_packet.velocity[1];
						spatial_msg.Twist.linear.z=system_state_packet.velocity[2];
						spatial_msg.Twist.angular.x=system_state_packet.angular_velocity[0];
						spatial_msg.Twist.angular.y=system_state_packet.angular_velocity[1];
						spatial_msg.Twist.angular.z=system_state_packet.angular_velocity[2];

						// IMU
						spatial_msg.Imu.header.stamp.sec=system_state_packet.unix_time_seconds;
						spatial_msg.Imu.header.stamp.nsec=system_state_packet.microseconds*1000;
						spatial_msg.Imu.header.frame_id=imu_frame_id;
						// Convert roll, pitch, yaw from radians to quaternion format //
						spatial_msg.RPY.roll = system_state_packet.orientation[0] ;
						spatial_msg.RPY.pitch = system_state_packet.orientation[1]  ;
						spatial_msg.RPY.yaw = system_state_packet.orientation[2]  ;

						geometry_msgs::Quaternion quat_msg = tf::createQuaternionMsgFromRollPitchYaw(
																spatial_msg.RPY.roll,
																spatial_msg.RPY.pitch,
																spatial_msg.RPY.yaw 	
															);

						spatial_msg.Imu.orientation.x= quat_msg.x ; 
						spatial_msg.Imu.orientation.y= quat_msg.y ;
						spatial_msg.Imu.orientation.z= quat_msg.z ;
						spatial_msg.Imu.orientation.w= quat_msg.w ;

						spatial_msg.Imu.angular_velocity.x=system_state_packet.angular_velocity[0]; // These the same as the TWIST msg values
						spatial_msg.Imu.angular_velocity.y=system_state_packet.angular_velocity[1];
						spatial_msg.Imu.angular_velocity.z=system_state_packet.angular_velocity[2];
						spatial_msg.Imu.linear_acceleration.x=system_state_packet.body_acceleration[0];
						spatial_msg.Imu.linear_acceleration.y=system_state_packet.body_acceleration[1];
						spatial_msg.Imu.linear_acceleration.z=system_state_packet.body_acceleration[2];

						// System Status
						system_status_msg.message = "";
						system_status_msg.level = 0; // default OK state
						if (system_state_packet.system_status.b.system_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "0. System Failure! ";
						}
						if (system_state_packet.system_status.b.accelerometer_sensor_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "1. Accelerometer Sensor Failure! ";
						}
						if (system_state_packet.system_status.b.gyroscope_sensor_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "2. Gyroscope Sensor Failure! ";
						}
						if (system_state_packet.system_status.b.magnetometer_sensor_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "3. Magnetometer Sensor Failure! ";
						}
						if (system_state_packet.system_status.b.pressure_sensor_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "4. Pressure Sensor Failure! ";
						}
						if (system_state_packet.system_status.b.gnss_failure) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "5. GNSS Failure! ";
						}
						if (system_state_packet.system_status.b.accelerometer_over_range) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "6. Accelerometer Over Range! ";
						}
						if (system_state_packet.system_status.b.gyroscope_over_range) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "7. Gyroscope Over Range! ";
						}
						if (system_state_packet.system_status.b.magnetometer_over_range) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "8. Magnetometer Over Range! ";
						}
						if (system_state_packet.system_status.b.pressure_over_range) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "9. Pressure Over Range! ";
						}
						if (system_state_packet.system_status.b.minimum_temperature_alarm) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "10. Minimum Temperature Alarm! ";
						}
						if (system_state_packet.system_status.b.maximum_temperature_alarm) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "11. Maximum Temperature Alarm! ";
						}
						if (system_state_packet.system_status.b.low_voltage_alarm) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "12. Low Voltage Alarm! ";
						}
						if (system_state_packet.system_status.b.high_voltage_alarm) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "13. High Voltage Alarm! ";
						}
						if (system_state_packet.system_status.b.gnss_antenna_disconnected) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "14. GNSS Antenna Disconnected! ";
						}
						if (system_state_packet.system_status.b.serial_port_overflow_alarm) {
							system_status_msg.level = 2; // ERROR state
							system_status_msg.message = system_status_msg.message + "15. Data Output Overflow Alarm! ";
						}

						// Filter Status
						filter_status_msg.message = "";
						filter_status_msg.level = 0; // default OK state
						if (system_state_packet.filter_status.b.orientation_filter_initialised) {
							filter_status_msg.message = filter_status_msg.message + "0. Orientation Filter Initialised. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "0. Orientation Filter NOT Initialised. ";
						}
						if (system_state_packet.filter_status.b.ins_filter_initialised) {
							filter_status_msg.message = filter_status_msg.message + "1. Navigation Filter Initialised. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "1. Navigation Filter NOT Initialised. ";
						}
						if (system_state_packet.filter_status.b.heading_initialised) {
							filter_status_msg.message = filter_status_msg.message + "2. Heading Initialised. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "2. Heading NOT Initialised. ";
						}
						if (system_state_packet.filter_status.b.utc_time_initialised) {
							filter_status_msg.message = filter_status_msg.message + "3. UTC Time Initialised. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "3. UTC Time NOT Initialised. ";
						}
						if (system_state_packet.filter_status.b.event1_flag) {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "7. Event 1 Occured. ";
						}
						else {
							filter_status_msg.message = filter_status_msg.message + "7. Event 1 NOT Occured. ";
						}
						if (system_state_packet.filter_status.b.event2_flag) {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "8. Event 2 Occured. ";
						}
						else {
							filter_status_msg.message = filter_status_msg.message + "8. Event 2 NOT Occured. ";
						}
						if (system_state_packet.filter_status.b.internal_gnss_enabled) {
							filter_status_msg.message = filter_status_msg.message + "9. Internal GNSS Enabled. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "9. Internal GNSS NOT Enabled. ";
						}
						if (system_state_packet.filter_status.b.magnetic_heading_enabled) {
							filter_status_msg.message = filter_status_msg.message + "10. Magnetic Heading Active. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "10. Magnetic Heading NOT Active. ";
						}
						if (system_state_packet.filter_status.b.velocity_heading_enabled) {
							filter_status_msg.message = filter_status_msg.message + "11. Velocity Heading Enabled. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "11. Velocity Heading NOT Enabled. ";
						}
						if (system_state_packet.filter_status.b.atmospheric_altitude_enabled) {
							filter_status_msg.message = filter_status_msg.message + "12. Atmospheric Altitude Enabled. ";
						}
						else {
							filter_status_msg.message = filter_status_msg.message + "12. Atmospheric Altitude NOT Enabled. ";
							filter_status_msg.level = 1; // WARN state
						}
						if (system_state_packet.filter_status.b.external_position_active) {
							filter_status_msg.message = filter_status_msg.message + "13. External Position Active. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "13. External Position NOT Active. ";
						}
						if (system_state_packet.filter_status.b.external_velocity_active) {
							filter_status_msg.message = filter_status_msg.message + "14. External Velocity Active. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "14. External Velocity NOT Active. ";
						}
						if (system_state_packet.filter_status.b.external_heading_active) {
							filter_status_msg.message = filter_status_msg.message + "15. External Heading Active. ";
						}
						else {
							filter_status_msg.level = 1; // WARN state
							filter_status_msg.message = filter_status_msg.message + "15. External Heading NOT Active. ";
						}
					}
				}


				if (an_packet->id == packet_id_euler_orientation_standard_deviation)
				{
					if(decode_euler_orientation_standard_deviation_packet(&euler_orientation_standard_deviation_packet, an_packet) == 0)
					{
						// IMU
						spatial_msg.Imu.orientation_covariance[0] = euler_orientation_standard_deviation_packet.standard_deviation[0];
						spatial_msg.Imu.orientation_covariance[4] = euler_orientation_standard_deviation_packet.standard_deviation[1];
						spatial_msg.Imu.orientation_covariance[8] = euler_orientation_standard_deviation_packet.standard_deviation[2];
					}
				
				}

				//testing
				if (an_packet->id == packet_id_velocity_standard_deviation)
				{
					if(decode_velocity_standard_deviation_packet(&velocity_standard_deviation_packet, an_packet) == 0)
					{
						// IMU
						spatial_msg.Imu.linear_acceleration_covariance[0] = velocity_standard_deviation_packet.standard_deviation[0];
						spatial_msg.Imu.linear_acceleration_covariance[4] = velocity_standard_deviation_packet.standard_deviation[1];
						spatial_msg.Imu.linear_acceleration_covariance[8] = velocity_standard_deviation_packet.standard_deviation[2];
					}
				}







				// Ensure that you free the an_packet when your done with it //
				// or you will leak memory                                   //
				an_packet_free(&an_packet);

				// Publish messages //
				spatial_pub.publish(spatial_msg);
				system_status_pub.publish(system_status_msg);
				filter_status_pub.publish(filter_status_msg);
			}
		}
	}

}
