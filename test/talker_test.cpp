///============================================================================
/// @file        : talker_test.cpp
/// @author      : gauraut
/// @version     : 1.0
/// @copyright   : MIT License
/// @brief       : Talker test definition
///============================================================================

#include <gtest/gtest.h>
#include <ros/ros.h>
#include "beginner_tutorials/chng_str.h"


TEST(Talker_test1, test_talker_chng_str)
{
  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::chng_str>("chng_str");
  beginner_tutorials::chng_str srv;
  srv.request.ip_str = "Hello, this is a test";
  client.call(srv);
  EXPECT_EQ(srv.response.op_str, "Hello, this is a test");
}

TEST(Talker_test2, test_talker_pub_rate)
{
  ros::NodeHandle nh;
  int x;
  nh.getParam("/talker/pub_rate", x);
  EXPECT_EQ(x, 15);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "chng_str_test_client");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
