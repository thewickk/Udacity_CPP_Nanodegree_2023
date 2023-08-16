#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
    public:
        Student(std::string name, int grade, float gpa);
        // Accessors
        std::string GetName() const;
        int GetGrade() const;
        float GetGPA() const;
        // Mutators
        void SetName(std::string name);
        void SetGrade(int grade);
        void SetGPA(float gpa);

    private:
        std::string name_;
        int grade_;
        float gpa_;
        void Validate();

};


#endif