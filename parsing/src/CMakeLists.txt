find_package(Boost COMPONENTS filesystem REQUIRED)

set(SRC_FILES
        beatmapset.cpp
        beatmap.cpp
        utils.cpp
        utils.hpp)

add_library(parsing STATIC ${SRC_FILES})
add_library(osutool::parsing ALIAS parsing)

target_link_libraries(parsing
        PRIVATE
            Boost::filesystem)
