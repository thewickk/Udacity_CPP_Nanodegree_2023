#include <iostream>
#include "../inc/car.h"
#include "../inc/bicycle.h"
#include "../inc/scooter.h"

int main()
{
    Car car;
    car.wheels =4;
    Bicycle bicycle;
    bicycle.Wheels(2);
    Scooter scooter;
    scooter.Wheels(2);


    return 0;
}