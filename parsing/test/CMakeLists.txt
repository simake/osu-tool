find_package(Boost COMPONENTS filesystem unit_test_framework REQUIRED)

add_executable(parsing_test test.cpp)

add_test(NAME parsing_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMMAND parsing_test)

target_link_libraries(parsing_test
        PRIVATE
            osutool::parsing
            Boost::unit_test_framework
            Boost::filesystem)
