cmake_minimum_required(VERSION 3.12)
project(osu_tool)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(include)

set(SRC_FILES
        src/main.cpp
        src/beatmapset.cpp
        src/beatmap.cpp
        src/config.cpp
        src/utils.cpp)

set(TEST_FILES
        test/test.cpp
        src/beatmapset.cpp
        src/beatmap.cpp
        src/config.cpp
        src/utils.cpp)

add_executable(osutool ${SRC_FILES})
add_executable(osutool_test ${TEST_FILES})

target_link_libraries(osutool
        Boost::filesystem)

target_link_libraries(osutool_test
        Boost::system
        Boost::unit_test_framework
        Boost::filesystem)
