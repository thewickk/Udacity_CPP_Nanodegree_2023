#include <iostream>
#include <stdlib.h>


class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    // constructor
    MyMovableClass(size_t size)
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int) << " bytes " << std::endl;
    }

    // destructor
    ~MyMovableClass()
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }

    // copy constructor
    MyMovableClass(const MyMovableClass &source)
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

    // copy assignment operator
    MyMovableClass &operator=(const MyMovableClass &source)
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        // check to see if self-assingment
        if (this == &source) return *this;

        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    // move constructor
    MyMovableClass(MyMovableClass &&source)
    {
        std::cout << "MOVING (c'tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    // move assignment operator
    MyMovableClass &operator=(MyMovableClass &&source)
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source) return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

int main()
{
    MyMovableClass obj1(10);        // obj1 created with class constructor
    MyMovableClass obj2(obj1);      // obj2 created using copy constructor
    obj2 = obj1;                    // obj2 modified to copy of obj1 using copy assignment operator
    return 0;
}