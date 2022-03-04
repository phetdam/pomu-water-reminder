cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED CMAKE_PREFIX_PATH)
set(CMAKE_PREFIX_PATH ./Qt6:/opt/Qt6.2.3)
endif()

# set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

include_directories(include)

add_library(gui STATIC utils.cc alert.cc ../../resources/resources.qrc)
target_compile_features(gui PUBLIC cxx_std_17)
target_link_libraries(gui PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
