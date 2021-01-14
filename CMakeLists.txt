cmake_minimum_required(VERSION 3.17)

project(noto C)

set(CMAKE_C_STANDARD 11)

include_directories("headers/")

set(SOURCES
    src/main.c
    src/create_new_db.c
    src/show_all.c
    src/show_entry.c
    src/create_entry.c
    src/delete_line.c
    src/remove_entry.c
    src/get_path_to_db.c
    src/generate_hash.c
)

add_executable(noto ${SOURCES})
