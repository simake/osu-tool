find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(SRC_FILES
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui)

add_executable(gui ${SRC_FILES})

target_link_libraries(gui
        PRIVATE
            Qt5::Core
            Qt5::Widgets)
