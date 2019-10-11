cmake_minimum_required(VERSION 3.0.2)
project(rospython)

# Expects ROS_PYTHON_VERSION from ros_environment)
find_package(PythonInterp $ENV{ROS_PYTHON_VERSION} REQUIRED)

find_package(catkin REQUIRED)
catkin_package()

add_executable(rospython src/rospython.c)
target_compile_definitions(rospython PRIVATE ROSPYTHON_PYTHON_VERSION="$ENV{ROS_PYTHON_VERSION}")
target_compile_definitions(rospython PRIVATE ROSPYTHON_PYTHON_PATH="${PYTHON_EXECUTABLE}")

install(TARGETS rospython
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
