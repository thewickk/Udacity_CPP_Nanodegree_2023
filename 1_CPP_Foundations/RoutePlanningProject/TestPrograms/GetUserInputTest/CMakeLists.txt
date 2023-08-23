cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -Wall")

project(GetUserInputTest)

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")

add_executable(main.elf src/main.cpp)