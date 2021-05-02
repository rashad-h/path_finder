#change this if you happen to be working with a lower version of CMake
cmake_minimum_required(VERSION 2.8)

project(route_finding)

#change this to Release to activate optimization and compile without debug symbols
set(CMAKE_BUILD_TYPE Debug)

#adds arbitrary flags to the compiler.
#this one is used to generate the files we give in input to Egypt.
set(CMAKE_C_FLAGS "-std=c99")

include_directories("Unity-master/include")

#creates an executable by compiling and linking a list of space separated C files.
add_executable(route_finding main.c logic.c input.c graphics.c)

add_executable(unit_tests_logic unit_tests_logic.c logic.c input.c graphics.c Unity-master/src/unity.c)
add_executable(unit_tests_input unit_tests_input.c input.c Unity-master/src/unity.c)
add_executable(unit_tests_graphics unit_tests_graphics.c graphics.c Unity-master/src/unity.c)