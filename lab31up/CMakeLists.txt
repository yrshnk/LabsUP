cmake_minimum_required(VERSION 3.16)

project(lab31up_tests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

set(PROJECT_SOURCES
    mainwindow.cpp
    mainwindow.h
    tests.cpp
)

add_executable(lab31up_tests
    ${PROJECT_SOURCES}
)

target_link_libraries(lab31up_tests PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets)


