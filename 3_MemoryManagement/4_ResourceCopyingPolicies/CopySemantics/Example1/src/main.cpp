#include <iostream>

class MyClass
{
private:
    int *_myInt;

public:
    MyClass()
    {
       _myInt = (int *)malloc(sizeof(int)); 
    }

    ~MyClass()
    {
        free(_myInt);
    }

    void printOwnAddress() 
    {
        std::cout << "Own address on the stack is: " << this << std::endl;
    }

    void printMemberAddress()
    {
        std::cout << "Manageing memory block on the heap at: " << _myInt << std::endl;
    }
};

int main()
{
    // instantinate object 1
    MyClass myClass1;
    myClass1.printOwnAddress();
    myClass1.printMemberAddress();

    // copy object 1 in to object 2
    MyClass myClass2(myClass1); // copy constructor
    myClass2.printOwnAddress();
    myClass2.printMemberAddress();
}