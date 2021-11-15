
#cmake_minimum_required(VERSION 3.0.2)
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation tf)

add_service_files(
  DIRECTORY
  srv
  FILES
  chng_str.srv
)
generate_messages(DEPENDENCIES std_msgs)
## Declare a catkin package
catkin_package(CATKIN_DEPENDS std_msgs message_runtime)


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

target_link_libraries(
  talker
  ${catkin_LIBRARIES}
)
add_dependencies(
  talker
  ${beginner_tutorials_EXPORTED_TARGETS}
)

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)

  add_rostest_gtest(
  talker_test
  launch/test.launch
  test/talker_test.cpp
  )
  target_link_libraries(
  talker_test
  ${catkin_LIBRARIES}
  )
  add_dependencies(
  talker_test
  talker
  ${PROJECT_NAME}_generate_messages_cpp
  ${catkin_EXPORTED_TARGETS}
  )
endif()
