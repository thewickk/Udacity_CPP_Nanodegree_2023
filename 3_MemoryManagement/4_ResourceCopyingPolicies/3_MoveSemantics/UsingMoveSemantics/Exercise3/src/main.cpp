/*
* Exercise 3: Instantiate a proprietary class for managing a template-based 
* heap resource using both copy and move semantics 
*/

#include <iostream>

// This class is for managing a template-based heap resource and 
// implements move semantics
template <class T>
class MyClass
{
private: 
    T *data = nullptr;

    // private copy constructor
    MyClass(const MyClass &);

    // private copy assignment operator
    MyClass &operator=(const MyClass &);

public:
    MyClass() {}

    // move constructor
    MyClass(MyClass &&other)
    {
        data = other.data;
        other.data = nullptr;
    }

    // move assignment operator
    MyClass &operator=(MyClass &&other)
    {
        if (this != &other)
        {
            if (data)
            {
                delete data;
            }

            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    ~MyClass()
    {
        if (data)
        {
            delete data;
        }
    }
};

int main()
{
    /* EXERCISE 3-1: create an instance h1 of class MyClass with data of 
       type 'double' using the regular constructor */
    // TODO: SOLUTION 3-1
    MyClass<double> h1; // regular constructor

    /* EXERCISE 3-2: create an instance h2 of class MyClass using the move 
       constructor (moving from h1) */
    // TODO: SOLUTION 3-2
    MyClass<double> h3 = std::move(h1);

    /* EXERCISE 3-3: disable copying for class MyClass */
    // TODO: SOLUTION 3-3

    return 0;
}