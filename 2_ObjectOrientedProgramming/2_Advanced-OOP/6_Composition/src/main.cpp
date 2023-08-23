#include <iostream>
#include <cassert>
#include "../inc/circle.h"

int main()
{
    LineSegment radius {3, "cowboys"};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
    return 0;
}