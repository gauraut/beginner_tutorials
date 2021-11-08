
#cmake_minimum_required(VERSION 3.0.2)
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

add_service_files(
  FILES
  chng_str.srv
)
## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

add_executable(chng_str_server src/chng_str_server.cpp)
target_link_libraries(chng_str_server ${catkin_LIBRARIES})
add_dependencies(chng_str_server beginner_tutorials_gencpp)

add_executable(chng_str_server src/chng_str_server.cpp)
target_link_libraries(chng_str_server ${catkin_LIBRARIES})
add_dependencies(chng_str_server beginner_tutorials_gencpp)



