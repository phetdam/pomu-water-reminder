cmake_minimum_required(VERSION 3.16)

if(NOT CMAKE_CXX_FLAGS MATCHES "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

if(NOT DEFINED CMAKE_PREFIX_PATH)
set(CMAKE_PREFIX_PATH ./Qt6:/opt/Qt6.2.3)
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# add_subdirectory(core)
add_subdirectory(gui)

include_directories(gui/include)

add_executable(pomwr main.cc)
target_compile_features(pomwr PRIVATE cxx_std_17)
# target_link_libraries(pomwr PRIVATE Qt6::Gui Qt6::Widgets core qwidgets)
target_link_libraries(pomwr PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets gui)