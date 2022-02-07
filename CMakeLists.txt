cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(noto C)

set(CMAKE_C_STANDARD 11)

include_directories("include/")

set(SOURCES
        noto.c
        lib/create_new_db.c
        lib/show_all.c
        lib/show_entry.c
        lib/create_entry.c
        lib/delete_line.c
        lib/remove_entry.c
        lib/get_path_to_db.c
        lib/generate_hash.c
        )

add_executable(noto ${SOURCES})
