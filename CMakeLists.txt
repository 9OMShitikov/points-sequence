cmake_minimum_required(VERSION 3.5)
project(points_loop)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)

add_executable(points_loop main.cpp points_sequence.h points_sequence.cpp)
target_link_libraries(points_loop gtest gtest_main)
