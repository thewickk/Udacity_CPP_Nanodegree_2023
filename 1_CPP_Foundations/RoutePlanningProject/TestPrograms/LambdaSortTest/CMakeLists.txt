cmake_minimum_required(VERSION 3.27.1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

project(LambdaSortTest)

add_executable(main.elf src/main.cpp)