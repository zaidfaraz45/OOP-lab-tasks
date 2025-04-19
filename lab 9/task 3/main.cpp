#include <iostream>
#include "Course.h"
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main()
{
    Course* course;

    LectureCourse lectureCourse("CS1004", 3);
    course = &lectureCourse;
    course->calculateGrade();
    course->displayInfo();

    LabCourse labCourse("CL1004", 1);
    course = &labCourse;
    course->calculateGrade();
    course->displayInfo();

    return 0;
}