cmake_minimum_required(VERSION 3.17)

project(noto VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add compile options
add_compile_options(-Wall -Wextra -Wpedantic)

# Include directories
include_directories(include)

# Use file(GLOB...) to automatically find source files
file(GLOB SOURCES "src/*.c")

add_executable(noto ${SOURCES})

target_include_directories(noto PRIVATE "headers/")

# Install target
install(TARGETS noto DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
