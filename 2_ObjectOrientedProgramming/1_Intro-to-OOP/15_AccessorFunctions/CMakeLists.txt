cmake_minimum_required(VERSION 3.27.1)

set(CMAKE_CXX_STANDARD 20)

project(AccessorFunctions)

add_executable(main.elf src/main.cpp src/bank_account.cpp)