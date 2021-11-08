#include "ros/ros.h"
#include "beginner_tutorials/chng_str.h"

void chng_str(beginner_tutorials::chng_str::Request  &req,
         beginner_tutorials::chng_str::Response &res)
{
  res.hw = req.ip;
  ROS_INFO("request: string = %s", (std::string)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%s]", (std::string)res.ip);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "chng_str");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("chng_str", chng_str);
  ROS_INFO("Ready to change base string.");
  ros::spin();

  return 0;
}
