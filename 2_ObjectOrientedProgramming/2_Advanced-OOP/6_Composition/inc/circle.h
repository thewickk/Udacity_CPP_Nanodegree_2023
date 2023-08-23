#ifndef CIRCLE_H
#define CIRCLE_H

#include "../inc/line_segment.h"

class Circle
{
    public:
        Circle(LineSegment&);
        double Area();
    
    private:
        LineSegment& radius_;
};

#endif