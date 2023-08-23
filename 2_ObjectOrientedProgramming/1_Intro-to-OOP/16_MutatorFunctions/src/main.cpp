#include <iostream>
#include "../inc/car.h"

int main()
{
    Car car;
    char brand[] = "Peugeot";
    car.SetCarBrand(brand);
    std::cout << car.GetCarBrand() << std::endl;

    return 0;
}