cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 20)

project(using_cmake)

add_executable(main.elf ../src/main.cpp ../src/increment_and_sum.cpp ../src/vect_add_one.cpp)



