#ifndef SCOOTER_H
#define SCOOTER_H

#include "../inc/vehicle.h"

class Scooter : private Vehicle
{
    public:
        bool electric {false};
        void Wheels(int);
};

#endif