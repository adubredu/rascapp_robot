// Generated by gencpp from file baxter_core_msgs/CloseCameraResponse.msg
// DO NOT EDIT!


#ifndef BAXTER_CORE_MSGS_MESSAGE_CLOSECAMERARESPONSE_H
#define BAXTER_CORE_MSGS_MESSAGE_CLOSECAMERARESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace baxter_core_msgs
{
template <class ContainerAllocator>
struct CloseCameraResponse_
{
  typedef CloseCameraResponse_<ContainerAllocator> Type;

  CloseCameraResponse_()
    : err(0)  {
    }
  CloseCameraResponse_(const ContainerAllocator& _alloc)
    : err(0)  {
  (void)_alloc;
    }



   typedef int32_t _err_type;
  _err_type err;




  typedef boost::shared_ptr< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> const> ConstPtr;

}; // struct CloseCameraResponse_

typedef ::baxter_core_msgs::CloseCameraResponse_<std::allocator<void> > CloseCameraResponse;

typedef boost::shared_ptr< ::baxter_core_msgs::CloseCameraResponse > CloseCameraResponsePtr;
typedef boost::shared_ptr< ::baxter_core_msgs::CloseCameraResponse const> CloseCameraResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace baxter_core_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'baxter_core_msgs': ['/home/baxter/ros_ws/src/baxter_common/baxter_core_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b6e094011a4dfaee5eddf447220446cf";
  }

  static const char* value(const ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb6e094011a4dfaeeULL;
  static const uint64_t static_value2 = 0x5eddf447220446cfULL;
};

template<class ContainerAllocator>
struct DataType< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "baxter_core_msgs/CloseCameraResponse";
  }

  static const char* value(const ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32           err\n\
\n\
";
  }

  static const char* value(const ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.err);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CloseCameraResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::baxter_core_msgs::CloseCameraResponse_<ContainerAllocator>& v)
  {
    s << indent << "err: ";
    Printer<int32_t>::stream(s, indent + "  ", v.err);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BAXTER_CORE_MSGS_MESSAGE_CLOSECAMERARESPONSE_H
