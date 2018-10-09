include_directories(include)

add_subdirectory(src)

if(BUILD_TEST)
    add_subdirectory(test)
endif()
