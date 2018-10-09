cmake_minimum_required(VERSION 3.12)
project(osu_tool)

set(CMAKE_CXX_STANDARD 11)

option(BUILD_TEST "Also build tests when building the project" ON)

if(BUILD_TEST)
    enable_testing()
endif()

add_subdirectory(parsing)
