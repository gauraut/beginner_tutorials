#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::chng_str>("Change base string");
  beginner_tutorials::chng_str srv;
  srv.request.ip = atoll(argv[1]);
  srv.request.hw = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Changed: %s", (std::string)srv.response.op);
  }
  else
  {
    ROS_ERROR("Failed to call service chng_str");
    return 1;
  }

  return 0;
}
