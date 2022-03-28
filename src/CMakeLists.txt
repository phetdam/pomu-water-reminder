cmake_minimum_required(VERSION 3.16)

# add_subdirectory(core)
add_subdirectory(gui)

include_directories(gui/include)

# note: resources don't load unless linked using add_executable
add_executable(qtwr main.cc ${PROJECT_SOURCE_DIR}/resources/resources.qrc)
target_compile_features(qtwr PRIVATE cxx_std_17)
# target_link_libraries(qtwr PRIVATE Qt6::Gui Qt6::Widgets core qwidgets)
target_link_libraries(qtwr PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets gui)
