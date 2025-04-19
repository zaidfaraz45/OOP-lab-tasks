#include <iostream>
#include "LectureCourse.h"
using namespace std;

LectureCourse::LectureCourse(string cC, int c): Course(cC, c) {}

void LectureCourse::calculateGrade() 
{
    cout << "Calculating grade for lecture course.....\n";
}

void LectureCourse::displayInfo() 
{
    cout << "Lecture Course Details:\n";
    cout << "Course is " << courseCode << endl;
    cout << "Credits - " << credits << endl << endl;
}