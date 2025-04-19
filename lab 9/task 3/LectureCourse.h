#include <iostream>
#include "Course.h"
#ifndef LECTURECOURSE
#define LECTURECOURSE
using namespace std;

class LectureCourse: public Course
{
    public:
        LectureCourse(string cC, int c);
        void calculateGrade() override;
        void displayInfo() override;
};

#endif