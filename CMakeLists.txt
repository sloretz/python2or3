cmake_minimum_required(VERSION 3.0.2)
project(python2or3)

# Expects ROS_PYTHON_VERSION from ros_environment)
find_package(PythonInterp $ENV{ROS_PYTHON_VERSION} REQUIRED)

find_package(catkin REQUIRED)
catkin_package()

add_executable(python2or3 src/python2or3.c)
target_compile_definitions(python2or3 PRIVATE PYTHON_VERSION="$ENV{ROS_PYTHON_VERSION}")
target_compile_definitions(python2or3 PRIVATE PYTHON_PATH="${PYTHON_EXECUTABLE}")

# Make `python2or3` work from the devel space
set_target_properties(python2or3 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/bin
)

# Make `rosrun python2or3 python2or3` work
install(PROGRAMS python2or3
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Make `python2or3` work from the install space
install(PROGRAMS python2or3
  DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
