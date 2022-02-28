cmake_minimum_required(VERSION 3.16)

project(
    pomu-water-reminder
    VERSION 0.1.0
    HOMEPAGE_URL "https://github.com/phetdam/pomu-water-reminder"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_PREFIX_PATH ./Qt6:/opt/Qt6.2.3)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

add_executable(pomwr src/main.cc)
target_link_libraries(pomwr PRIVATE Qt6::Gui Qt6::Widgets)