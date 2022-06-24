cmake_minimum_required(VERSION 3.20)
project(lab C)

set(CMAKE_C_STANDARD 99)

add_executable(lab src/main.c inc/errors.h inc/allocation.h inc/matrix_transformation.h src/matrix_transformation.c src/allocation.c)
