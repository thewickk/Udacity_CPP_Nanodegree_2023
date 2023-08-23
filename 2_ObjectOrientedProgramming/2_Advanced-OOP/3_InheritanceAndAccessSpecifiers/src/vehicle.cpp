#include "../inc/vehicle.h"
#include <iostream>

void Vehicle::Print() const
{
    std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!" << std::endl;
}
