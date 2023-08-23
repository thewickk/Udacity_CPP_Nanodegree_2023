cmake_minimum_required(VERSION 3.27.1)
set(CMAKE_CXX_STANDARD 20)
project(Vehicle_Inheritance)
add_executable(main.elf src/main.cpp src/vehicle.cpp src/bicycle.cpp src/scooter.cpp src/car.cpp)