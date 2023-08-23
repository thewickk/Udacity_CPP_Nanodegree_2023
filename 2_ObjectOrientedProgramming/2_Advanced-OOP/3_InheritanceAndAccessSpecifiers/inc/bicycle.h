#ifndef BICYCLE_H
#define BICYCLE_H

#include "../inc/vehicle.h"

class Bicycle : protected Vehicle
{
    public:
        bool kickstand {true};
        void Wheels(int);
};

#endif