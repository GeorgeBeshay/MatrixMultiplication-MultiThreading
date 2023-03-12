cmake_minimum_required(VERSION 3.24)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src programDriver.c programDriver.h)
