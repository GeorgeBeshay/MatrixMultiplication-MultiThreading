cmake_minimum_required(VERSION 3.24)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src main.c main.h matrix_utilities.c matrix_utilities.h matrix_scanner.c matrix_scanner.h)
