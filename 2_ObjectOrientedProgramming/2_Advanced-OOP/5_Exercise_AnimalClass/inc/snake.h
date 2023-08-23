#ifndef SNAKE_H
#define SNAKE_H

#include "../inc/animal.h"

class Snake : public Animal
{
    public:
        int length;
        void MakeSound() const;
};

#endif