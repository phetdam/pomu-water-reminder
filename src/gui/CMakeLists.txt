cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED CMAKE_PREFIX_PATH)
set(CMAKE_PREFIX_PATH ./Qt6:/opt/Qt6.2.3)
endif()

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

include_directories(include)

add_library(
    gui
    STATIC
    aboutdialog.cc
    alertdialog.cc
    keydialog.cc
    mainwindow.cc
    prefsdialog.cc
    utils.cc
)
target_compile_features(gui PUBLIC cxx_std_17)
target_link_libraries(gui PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
