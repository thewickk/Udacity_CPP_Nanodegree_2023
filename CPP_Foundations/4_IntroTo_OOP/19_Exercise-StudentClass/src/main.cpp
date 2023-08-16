#include <iostream>
#include <cassert>
#include "../inc/student.h"

int main()
{
    Student david("David Silver", 10, 4.0);
    assert(david.GetName() == "David Silver");
    assert(david.GetGrade() == 10);
    assert(david.GetGPA() == 4.0);

    bool caught{false};

    try
    {
        david.SetGrade(20);
    }
    catch(...)
    {
        caught = true;
    }

    assert(caught);
    
}