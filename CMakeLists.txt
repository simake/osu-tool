cmake_minimum_required(VERSION 3.12)
project(osu_tool)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TEST "Also build tests when building the project" ON)

if(BUILD_TEST)
    enable_testing()
endif()

add_subdirectory(parsing)
add_subdirectory(gui)
