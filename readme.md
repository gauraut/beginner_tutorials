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
### Call rosservice
```
rosservice call /chng_str "your string here"
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
### Run rostest
```
roscd
cd ..
catkin_make run_tests
```
OR
```
rostest -t beginner_tutorials test.launch
```
## Bag files
### Recording with the launch file
```
roslaunch beginner_tutorials week10.launch record_talker:=true #by defalt, is set to false
```
The rosbag will be saved in the package's launch folder with th name as "sample.bag"
### Disabling bag file recording
By default, the rosbag recording is disabled. Just run the launch file.
### Inspecting the bag file
```
rosbag info your_rosbag_file.bag
```
Example output:
```
path:        2021-11-14-21-16-20.bag
version:     2.0
duration:    18.3s
start:       Nov 14 2021 21:16:20.10 (1636942580.10)
end:         Nov 14 2021 21:16:38.43 (1636942598.43)
size:        94.6 KB
messages:    542
compression: none [1/1 chunks]
types:       rosgraph_msgs/Log [acffd30cd6b6de30f120938c17c593fb]
             std_msgs/String   [992ce8a1687cec8c8bd883ec73ca41d1]
topics:      /chatter   271 msgs    : std_msgs/String  
             rosout     271 msgs    : rosgraph_msgs/Log (2 connections)

```
### Playing the recorded rosbag file with listener node demonstration
In a new terminal
```
roscore
```
On a separate terminal
```
rosbag play file_name.bag
```
On a new terminal
```
rosrun beginner_tutorials listener
```
