cmake_minimum_required(VERSION 3.30)
project(Midterm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(MIDTERM_BUILD_TESTS ON)

add_library(
midterm
Source/Handler.cpp
Source/Handler.h
)

target_link_libraries(midterm -libstdc++ -libgcc -static)