#include <iostream>
#ifndef COURSE
#define COURSE
using namespace std;

class Course
{
    protected:
        string courseCode;
        int credits;

    public:
        Course(string cC, int c): courseCode(cC), credits(c) {}
        virtual void calculateGrade() = 0;
        virtual void displayInfo() = 0;
};

#endif