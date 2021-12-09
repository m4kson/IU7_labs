cmake_minimum_required(VERSION 3.20)
project(lab_07_1_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_07_1_1 src/main.c src/funcs.c inc/funcs.h unit_tests/check_main.c unit_tests/check_funcs.c)
