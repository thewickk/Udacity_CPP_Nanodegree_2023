#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
    public:
        int wheels {0};
        std::string color {"blue"};
        std::string make {"generic"};
        void Print() const;
};

#endif