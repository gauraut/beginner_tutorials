///============================================================================
/// @file        : talker.cpp
/// @author      : gauraut
/// @version     : 1.0
/// @copyright   : MIT License
/// @brief       : Talker definition
///============================================================================
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/chng_str.h"
#include <tf/transform_broadcaster.h>
extern std::string str = "Hello, this is Gaurav.";
extern std::string tlk = "talker";
/// @fn bool chng_str(beginner_tutorials::chng_str::Request&,
///  beginner_tutorials::chng_str::Response&)
/// @brief The chng_str function which is used by
///  the service chng_str to change the base string
///
/// @pre
/// @post
/// @param req
/// @param res
/// @return
bool chng_str(beginner_tutorials::chng_str::Request  &req,
         beginner_tutorials::chng_str::Response &res) {
  res.op_str = req.ip_str;
  str = res.op_str;
  ROS_WARN_STREAM(str << " is now " << res.op_str);
  return true;
}


/// @fn int main(int, char**)
/// @brief This tutorial demonstrates simple
/// sending of messages over the ROS system.
///
/// @pre
/// @post
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  int pub_rate = 10;
  n.getParam("/talker/pub_rate", pub_rate);
  ROS_FATAL_STREAM("If " << pub_rate << " is"
      " equal to zero, then no messages will be transmitted.");
  ROS_INFO_STREAM("Got parameter : " << pub_rate);
  ROS_DEBUG_STREAM(pub_rate << " is the current pub_rate");
  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("chng_str", chng_str);
  ros::Rate loop_rate(pub_rate);
  
  static tf::TransformBroadcaster talk;
  tf::Transform transform;
  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;

  while (ros::ok()) {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;
    ROS_DEBUG_STREAM("Message data will be changed.");
    std::stringstream ss;
    ss << str << count;
    msg.data = ss.str();
    ROS_DEBUG_STREAM("" << msg.data.c_str());
    transform.setOrigin( tf::Vector3(20, 45, 0.0) );
    tf::Quaternion q;
    q.setRPY(0, 0, 3.14);
    transform.setRotation(q);
    talk.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world",
    tlk));
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
