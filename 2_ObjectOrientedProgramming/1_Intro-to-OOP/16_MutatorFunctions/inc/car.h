#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
    public:
        
        // Accessors
        double GetCartHorsePower() const;
        double GetCarWeight() const;
        std::string GetCarBrand() const;

        // Mutators
        void SetCarHorsePower(double);
        void SetCarWeight(double);
        void SetCarBrand(char*);

    private:
        double horse_power_;
        double weight_;
        std::string brand_;
};

#endif // CAR_H