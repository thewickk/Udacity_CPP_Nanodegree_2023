#include <iostream>
#include <cassert>
#include "../inc/pyramid.h"

int main()
{
    Pyramid pyramid(4, 5, 6);
    assert(pyramid.GetLength() == 4);
    assert(pyramid.GetWidth() == 5);
    assert(pyramid.GetHeight() == 6);
    assert(pyramid.Volume() == 40);
    return 0;

    bool caught{false};

    try 
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch(...)
    {
        caught = true;
    }

    assert(caught);
}