# Beginner tutorials
## Overview
This code has a simple publisher subscriber code. The code has been modified to add service to the talker node which changes the base string. Also, a launch file has been added for the system. This launch file take an input argument pub_rate which changes the publishing rate of the talker node.
## License
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
MIT License

Copyright (c) 2021 Gaurav

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
## Dependencies

   - ROS Noetic
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
git clone https://github.com/gauraut/beginner_tutorials.git
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
rosrun beginner_tutorials talker
```
### To run the subscriber node
```
rosrun beginner_tutorials listener
```
### To run the launch file
```
roslaunch beginner_tutorials week10.launch pub_rate:=15 # Can set pub_rate to any required integer
```
### To run rqt console and rqt logging
  - In separate terminal
```
rosrun rqt_console rqt_console
```
  - In separate terminal
```
rosrun rqt_logger_level rqt_logger_level
```
