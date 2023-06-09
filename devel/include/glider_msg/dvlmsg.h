// Generated by gencpp from file glider_msg/dvlmsg.msg
// DO NOT EDIT!


#ifndef GLIDER_MSG_MESSAGE_DVLMSG_H
#define GLIDER_MSG_MESSAGE_DVLMSG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace glider_msg
{
template <class ContainerAllocator>
struct dvlmsg_
{
  typedef dvlmsg_<ContainerAllocator> Type;

  dvlmsg_()
    : header()
    , errCode()
    , dataGood()
    , altitudeBeam()
    , bottomVelocityBeam()
    , waterVelocityBeam()
    , waterVelocityCredit()
    , velocityInst()
    , velocityInstFlag(0)
    , velocityEarth()
    , velocityEarthFlag(0)
    , waterVelocityInst()
    , waterVelocityInstFlag(0)
    , waterVelocityEarth()
    , waterVelocityEarthFlag(0)
    , roll(0.0)
    , pitch(0.0)
    , heading(0.0)
    , altitude(0.0)
    , temperature(0.0)
    , pressure(0.0)
    , salinity(0.0)
    , soundSpeed(0.0)
    , rawData()  {
      dataGood.assign(0);

      altitudeBeam.assign(0.0);

      bottomVelocityBeam.assign(0.0);

      waterVelocityBeam.assign(0.0);

      waterVelocityCredit.assign(0.0);

      velocityInst.assign(0.0);

      velocityEarth.assign(0.0);

      waterVelocityInst.assign(0.0);

      waterVelocityEarth.assign(0.0);
  }
  dvlmsg_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , errCode(_alloc)
    , dataGood()
    , altitudeBeam()
    , bottomVelocityBeam()
    , waterVelocityBeam()
    , waterVelocityCredit()
    , velocityInst()
    , velocityInstFlag(0)
    , velocityEarth()
    , velocityEarthFlag(0)
    , waterVelocityInst()
    , waterVelocityInstFlag(0)
    , waterVelocityEarth()
    , waterVelocityEarthFlag(0)
    , roll(0.0)
    , pitch(0.0)
    , heading(0.0)
    , altitude(0.0)
    , temperature(0.0)
    , pressure(0.0)
    , salinity(0.0)
    , soundSpeed(0.0)
    , rawData(_alloc)  {
  (void)_alloc;
      dataGood.assign(0);

      altitudeBeam.assign(0.0);

      bottomVelocityBeam.assign(0.0);

      waterVelocityBeam.assign(0.0);

      waterVelocityCredit.assign(0.0);

      velocityInst.assign(0.0);

      velocityEarth.assign(0.0);

      waterVelocityInst.assign(0.0);

      waterVelocityEarth.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _errCode_type;
  _errCode_type errCode;

   typedef boost::array<int16_t, 4>  _dataGood_type;
  _dataGood_type dataGood;

   typedef boost::array<float, 4>  _altitudeBeam_type;
  _altitudeBeam_type altitudeBeam;

   typedef boost::array<float, 4>  _bottomVelocityBeam_type;
  _bottomVelocityBeam_type bottomVelocityBeam;

   typedef boost::array<float, 4>  _waterVelocityBeam_type;
  _waterVelocityBeam_type waterVelocityBeam;

   typedef boost::array<float, 4>  _waterVelocityCredit_type;
  _waterVelocityCredit_type waterVelocityCredit;

   typedef boost::array<float, 3>  _velocityInst_type;
  _velocityInst_type velocityInst;

   typedef int16_t _velocityInstFlag_type;
  _velocityInstFlag_type velocityInstFlag;

   typedef boost::array<float, 3>  _velocityEarth_type;
  _velocityEarth_type velocityEarth;

   typedef int16_t _velocityEarthFlag_type;
  _velocityEarthFlag_type velocityEarthFlag;

   typedef boost::array<float, 3>  _waterVelocityInst_type;
  _waterVelocityInst_type waterVelocityInst;

   typedef int16_t _waterVelocityInstFlag_type;
  _waterVelocityInstFlag_type waterVelocityInstFlag;

   typedef boost::array<float, 3>  _waterVelocityEarth_type;
  _waterVelocityEarth_type waterVelocityEarth;

   typedef int16_t _waterVelocityEarthFlag_type;
  _waterVelocityEarthFlag_type waterVelocityEarthFlag;

   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _heading_type;
  _heading_type heading;

   typedef float _altitude_type;
  _altitude_type altitude;

   typedef float _temperature_type;
  _temperature_type temperature;

   typedef float _pressure_type;
  _pressure_type pressure;

   typedef float _salinity_type;
  _salinity_type salinity;

   typedef float _soundSpeed_type;
  _soundSpeed_type soundSpeed;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _rawData_type;
  _rawData_type rawData;





  typedef boost::shared_ptr< ::glider_msg::dvlmsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::glider_msg::dvlmsg_<ContainerAllocator> const> ConstPtr;

}; // struct dvlmsg_

typedef ::glider_msg::dvlmsg_<std::allocator<void> > dvlmsg;

typedef boost::shared_ptr< ::glider_msg::dvlmsg > dvlmsgPtr;
typedef boost::shared_ptr< ::glider_msg::dvlmsg const> dvlmsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::glider_msg::dvlmsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::glider_msg::dvlmsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::glider_msg::dvlmsg_<ContainerAllocator1> & lhs, const ::glider_msg::dvlmsg_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.errCode == rhs.errCode &&
    lhs.dataGood == rhs.dataGood &&
    lhs.altitudeBeam == rhs.altitudeBeam &&
    lhs.bottomVelocityBeam == rhs.bottomVelocityBeam &&
    lhs.waterVelocityBeam == rhs.waterVelocityBeam &&
    lhs.waterVelocityCredit == rhs.waterVelocityCredit &&
    lhs.velocityInst == rhs.velocityInst &&
    lhs.velocityInstFlag == rhs.velocityInstFlag &&
    lhs.velocityEarth == rhs.velocityEarth &&
    lhs.velocityEarthFlag == rhs.velocityEarthFlag &&
    lhs.waterVelocityInst == rhs.waterVelocityInst &&
    lhs.waterVelocityInstFlag == rhs.waterVelocityInstFlag &&
    lhs.waterVelocityEarth == rhs.waterVelocityEarth &&
    lhs.waterVelocityEarthFlag == rhs.waterVelocityEarthFlag &&
    lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.heading == rhs.heading &&
    lhs.altitude == rhs.altitude &&
    lhs.temperature == rhs.temperature &&
    lhs.pressure == rhs.pressure &&
    lhs.salinity == rhs.salinity &&
    lhs.soundSpeed == rhs.soundSpeed &&
    lhs.rawData == rhs.rawData;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::glider_msg::dvlmsg_<ContainerAllocator1> & lhs, const ::glider_msg::dvlmsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace glider_msg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::glider_msg::dvlmsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::glider_msg::dvlmsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::glider_msg::dvlmsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::glider_msg::dvlmsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::glider_msg::dvlmsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::glider_msg::dvlmsg_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::glider_msg::dvlmsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c18145d5becba32686a61649fd23cb97";
  }

  static const char* value(const ::glider_msg::dvlmsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc18145d5becba326ULL;
  static const uint64_t static_value2 = 0x86a61649fd23cb97ULL;
};

template<class ContainerAllocator>
struct DataType< ::glider_msg::dvlmsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "glider_msg/dvlmsg";
  }

  static const char* value(const ::glider_msg::dvlmsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::glider_msg::dvlmsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"string errCode\n"
"int16[4] dataGood\n"
"float32[4] altitudeBeam\n"
"float32[4] bottomVelocityBeam\n"
"float32[4] waterVelocityBeam\n"
"float32[4] waterVelocityCredit\n"
"float32[3] velocityInst\n"
"int16 velocityInstFlag\n"
"float32[3] velocityEarth\n"
"int16 velocityEarthFlag\n"
"float32[3] waterVelocityInst\n"
"int16 waterVelocityInstFlag\n"
"float32[3] waterVelocityEarth\n"
"int16 waterVelocityEarthFlag\n"
"float32 roll\n"
"float32 pitch\n"
"float32 heading\n"
"float32 altitude\n"
"float32 temperature\n"
"float32 pressure\n"
"float32 salinity\n"
"float32 soundSpeed\n"
"string rawData\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::glider_msg::dvlmsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::glider_msg::dvlmsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.errCode);
      stream.next(m.dataGood);
      stream.next(m.altitudeBeam);
      stream.next(m.bottomVelocityBeam);
      stream.next(m.waterVelocityBeam);
      stream.next(m.waterVelocityCredit);
      stream.next(m.velocityInst);
      stream.next(m.velocityInstFlag);
      stream.next(m.velocityEarth);
      stream.next(m.velocityEarthFlag);
      stream.next(m.waterVelocityInst);
      stream.next(m.waterVelocityInstFlag);
      stream.next(m.waterVelocityEarth);
      stream.next(m.waterVelocityEarthFlag);
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.heading);
      stream.next(m.altitude);
      stream.next(m.temperature);
      stream.next(m.pressure);
      stream.next(m.salinity);
      stream.next(m.soundSpeed);
      stream.next(m.rawData);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct dvlmsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::glider_msg::dvlmsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::glider_msg::dvlmsg_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "errCode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.errCode);
    s << indent << "dataGood[]" << std::endl;
    for (size_t i = 0; i < v.dataGood.size(); ++i)
    {
      s << indent << "  dataGood[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.dataGood[i]);
    }
    s << indent << "altitudeBeam[]" << std::endl;
    for (size_t i = 0; i < v.altitudeBeam.size(); ++i)
    {
      s << indent << "  altitudeBeam[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.altitudeBeam[i]);
    }
    s << indent << "bottomVelocityBeam[]" << std::endl;
    for (size_t i = 0; i < v.bottomVelocityBeam.size(); ++i)
    {
      s << indent << "  bottomVelocityBeam[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.bottomVelocityBeam[i]);
    }
    s << indent << "waterVelocityBeam[]" << std::endl;
    for (size_t i = 0; i < v.waterVelocityBeam.size(); ++i)
    {
      s << indent << "  waterVelocityBeam[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.waterVelocityBeam[i]);
    }
    s << indent << "waterVelocityCredit[]" << std::endl;
    for (size_t i = 0; i < v.waterVelocityCredit.size(); ++i)
    {
      s << indent << "  waterVelocityCredit[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.waterVelocityCredit[i]);
    }
    s << indent << "velocityInst[]" << std::endl;
    for (size_t i = 0; i < v.velocityInst.size(); ++i)
    {
      s << indent << "  velocityInst[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.velocityInst[i]);
    }
    s << indent << "velocityInstFlag: ";
    Printer<int16_t>::stream(s, indent + "  ", v.velocityInstFlag);
    s << indent << "velocityEarth[]" << std::endl;
    for (size_t i = 0; i < v.velocityEarth.size(); ++i)
    {
      s << indent << "  velocityEarth[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.velocityEarth[i]);
    }
    s << indent << "velocityEarthFlag: ";
    Printer<int16_t>::stream(s, indent + "  ", v.velocityEarthFlag);
    s << indent << "waterVelocityInst[]" << std::endl;
    for (size_t i = 0; i < v.waterVelocityInst.size(); ++i)
    {
      s << indent << "  waterVelocityInst[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.waterVelocityInst[i]);
    }
    s << indent << "waterVelocityInstFlag: ";
    Printer<int16_t>::stream(s, indent + "  ", v.waterVelocityInstFlag);
    s << indent << "waterVelocityEarth[]" << std::endl;
    for (size_t i = 0; i < v.waterVelocityEarth.size(); ++i)
    {
      s << indent << "  waterVelocityEarth[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.waterVelocityEarth[i]);
    }
    s << indent << "waterVelocityEarthFlag: ";
    Printer<int16_t>::stream(s, indent + "  ", v.waterVelocityEarthFlag);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "heading: ";
    Printer<float>::stream(s, indent + "  ", v.heading);
    s << indent << "altitude: ";
    Printer<float>::stream(s, indent + "  ", v.altitude);
    s << indent << "temperature: ";
    Printer<float>::stream(s, indent + "  ", v.temperature);
    s << indent << "pressure: ";
    Printer<float>::stream(s, indent + "  ", v.pressure);
    s << indent << "salinity: ";
    Printer<float>::stream(s, indent + "  ", v.salinity);
    s << indent << "soundSpeed: ";
    Printer<float>::stream(s, indent + "  ", v.soundSpeed);
    s << indent << "rawData: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.rawData);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GLIDER_MSG_MESSAGE_DVLMSG_H
