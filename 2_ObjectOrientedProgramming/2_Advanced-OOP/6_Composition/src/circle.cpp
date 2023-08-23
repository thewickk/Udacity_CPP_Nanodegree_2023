#include "../inc/circle.h"
#include <cmath>

Circle::Circle(LineSegment& radius) 
    : radius_{radius} 
{

}

double Circle::Area()
{
    return pow(Circle::radius_.length, 2) * PI;
}