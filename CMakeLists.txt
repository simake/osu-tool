cmake_minimum_required(VERSION 3.12)
project(osu_tool)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS filesystem REQUIRED)

include_directories(include)

add_executable(osutool
        src/main.cpp
        src/beatmap.cpp)

target_link_libraries(osutool Boost::filesystem)
