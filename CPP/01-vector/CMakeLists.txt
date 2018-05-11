cmake_minimum_required(VERSION 3.5)
project(01-vector)

set(SOURCE_FILES main.cpp vector.cpp)
add_definitions(-std=c++11)

add_executable(run_vector ${SOURCE_FILES})
