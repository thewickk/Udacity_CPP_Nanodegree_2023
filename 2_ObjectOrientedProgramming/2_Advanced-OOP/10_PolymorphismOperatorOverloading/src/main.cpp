#include <cassert>

// TODO: Define Point class
class Point
{
    public:
        // TODO: Define public constructor
    Point(int x = 0, int y = 0) : x_{x}, y_{y} {}
    
    // TODO: Define + operator overload
    Point operator+(const Point& addend)
    {
        Point sum;
        sum.x_ = x_ + addend.x_;
        sum.y_ = y_ + addend.y_;
        return sum;
    }

    // TODO: Declare attributes x and y
    int x_;
    int y_;

};



// Test in main()
int main()
{
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2; // An example call to "operator +"
    assert(p3.x_ == p1.x_ + p2.x_);
    assert(p3.y_ == p1.y_ + p2.y_);
    return 0;
}