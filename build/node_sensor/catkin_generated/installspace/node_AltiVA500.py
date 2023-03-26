#!/usr/bin/env python2
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    pub1 = rospy.Publisher('depth', String, queue_size=10)
    pub2 = rospy.Publisher('distanceOAS', String, queue_size=10)
    rospy.init_node('node_AltiVA500')
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        depth = "depth %s" % rospy.get_time()
        distance = "distance %s" % rospy.get_time()
        # rospy.loginfo(depth)
        pub1.publish(depth)
        pub2.publish(distance)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
