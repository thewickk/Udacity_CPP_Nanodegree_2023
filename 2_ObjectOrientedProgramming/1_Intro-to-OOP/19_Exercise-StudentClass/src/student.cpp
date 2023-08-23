#include "../inc/student.h"
#include <stdexcept>

Student::Student(std::string name, int grade, float gpa)
    : name_{name}, grade_{grade}, gpa_{gpa} 
{
    Validate();
}

// Accessors
std::string Student::GetName() const { return name_; }
int Student::GetGrade() const { return grade_; }
float Student::GetGPA() const { return gpa_; }

// Mutators
void Student::SetName(std::string name)
{
    name_ = name;
}

void Student::SetGrade(int grade)
{
    grade_ = grade;
    Validate();
}

void Student::SetGPA(float gpa)
{
    gpa_ = gpa;
    Validate();
}

void Student::Validate()
{
    if (GetGrade() < 0 || GetGrade() > 12 || GetGPA() < 0.0 || GetGPA() > 4.0)
    {
        throw std::invalid_argument("argument out of bounds");
    }
}