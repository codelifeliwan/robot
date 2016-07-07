cmake_minimum_required(VERSION 3.5)
project(robot)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lasound")

set(SOURCE_FILES start.c head/robot_header.h head/brain.c test.c util/playsound.c util/robot_util.h)

add_executable(robot ${SOURCE_FILES})
