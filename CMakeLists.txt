cmake_minimum_required(VERSION 3.16)

project(
    qt-water-reminder
    VERSION 0.1.0
    HOMEPAGE_URL "https://github.com/phetdam/qt-water-reminder"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")

add_subdirectory(src)
