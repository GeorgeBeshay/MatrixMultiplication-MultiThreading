cmake_minimum_required(VERSION 3.24)
project(src C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(src main.c main.h matrix_utilities.c matrix_utilities.h matrix_io.c matrix_io.h different_approaches.c different_approaches.h)
