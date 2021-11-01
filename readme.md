# Beginner tutorials
## Overview
This is a simple publisher subscriber ROS Node tutorial.
## Dependencies

   - ROS Melodic
   - Modern C++ Programming Language
   - Std_Msgs Package
   - Roscpp Package
   - Catkin_Make build system

## Build

### Create Catkin Workspace
```
cd ~/catkin_ws
catkin_make clean && catkin_make
```
### Copy the repository in src folder of catkin workspace
```
cd src 
git clone https://github.com/advaitp/beginner_tutorials.git
cd ..
catkin_make clean && catkin_make
source ./devel/setup.bash
```

## Run

### Make sure Roscore is running
```
roscore
```
### Make sure you have sourced setup file
```
cd ~/catkin_ws
source ./devel/setup.bash
```
### To run the publisher node
```
rosrun beginner_tutorials publisher
```
### To run the subscriber node
```
rosrun beginner_tutorials subscriber
```
