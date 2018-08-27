cmake_minimum_required(VERSION 3.12)

project(noto C)

set(CMAKE_C_STANDARD 11)

add_executable(noto noto.c ./functions.c ./functions.h)
