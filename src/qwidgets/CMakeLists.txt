cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED CMAKE_PREFIX_PATH)
set(CMAKE_PREFIX_PATH ./Qt6:/opt/Qt6.2.3)
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_library(qwidgets STATIC miscutils.cc notification.cc)
target_compile_features(qwidgets PUBLIC cxx_std_17)
target_link_libraries(qwidgets PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)