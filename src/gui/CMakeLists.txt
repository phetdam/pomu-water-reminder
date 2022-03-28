cmake_minimum_required(VERSION 3.16)

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
