#include "../inc/car.h"

// Accessors
double Car::GetCartHorsePower() const { return horse_power_; }
double Car::GetCarWeight() const { return weight_; }
std::string Car::GetCarBrand() const { return brand_; }

// Mutators
void Car::SetCarHorsePower(double hp)
{
    horse_power_ = hp;
}

void Car::SetCarWeight(double weight)
{
    weight_ = weight;
}

void Car::SetCarBrand(char* brand)
{
    brand_ = brand;
}