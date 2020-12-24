cmake_minimum_required(VERSION 3.17)

project(noto C)

set(CMAKE_C_STANDARD 11)

add_executable(noto main.c ./functions.c ./functions.h)
