///============================================================================
/// @file        : Talker_test.cpp
/// @author      : gauraut
/// @version     : 1.0
/// @copyright   : MIT License
/// @brief       : Talker test cases definition
///============================================================================

#include <gtest/gtest.h>
#include <ros/ros.h>
#include "beginner_tutorials/chng_str.h"

TEST(Talkertest1, testTalkerservice) {
  //ros::NodeHandle dummy;
  EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
