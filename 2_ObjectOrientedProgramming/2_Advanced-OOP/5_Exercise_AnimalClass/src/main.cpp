#include "../inc/cat.h"
#include "../inc/snake.h"
#include <iostream>

int main()
{
    Cat cat;
    Snake snake;

    cat.age = 10;
    cat.name = "Lucy";
    cat.MakeSound();
    snake.MakeSound();

    std::cout << cat.age << " " << cat.name << std::endl;

    return 0;
}