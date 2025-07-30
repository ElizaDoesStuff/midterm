cmake_minimum_required(VERSION 3.30)
project(Midterm)

add_library(midterm Source/midterm.cpp)

add_executable(test Tests/Input/main.cpp)
target_link_libraries(test midterm)