cmake_minimum_required(VERSION 3.30)
project(Midterm)

set(MIDTERM_BUILD_TESTS ON)

add_library(midterm Source/midterm.cpp)

if (MIDTERM_BUILD_TESTS)
	add_executable(keyinput Tests/KeyInput/main.cpp)
	target_link_libraries(keyinput midterm)
endif()