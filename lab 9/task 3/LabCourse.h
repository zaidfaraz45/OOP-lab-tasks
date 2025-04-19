#include <iostream>
#include "Course.h"
#ifndef LABCOURSE
#define LABCOURSE
using namespace std;

class LabCourse: public Course
{
    public:
        LabCourse(string cC, int c);
        void calculateGrade() override;
        void displayInfo() override;
};

#endif