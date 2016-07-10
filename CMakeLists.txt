cmake_minimum_required(VERSION 3.5)
project(robot)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lasound")

set(SOURCE_FILES start.c head/robot_header.h head/brain.c examples/test.c util/playsound.c util/robot_util.h ears/robot_ears.h ears/ear_params.c ears/ear_ops.c speaker/robot_speaker.h speaker/speaker_params.c speaker/speaker_ops.c)

add_executable(robot ${SOURCE_FILES})
