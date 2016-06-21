cmake_minimum_required(VERSION 3.5)
project(robot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES start.c)
add_executable(robot ${SOURCE_FILES})