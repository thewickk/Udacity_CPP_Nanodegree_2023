#ifndef CAT_H
#define CAT_H

#include "../inc/animal.h"

class Cat : public Animal
{
    public:
        double height;
        void MakeSound() const;
};

#endif