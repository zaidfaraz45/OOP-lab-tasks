#include <iostream>
#include "LabCourse.h"
using namespace std;

LabCourse::LabCourse(string cC, int c): Course(cC, c) {}

void LabCourse::calculateGrade() 
{
    cout << "Calculating grade for lab course.....\n";
}

void LabCourse::displayInfo() 
{
    cout << "Lab Course Details:\n";
    cout << "Course is " << courseCode << endl;
    cout << "Credits - " << credits << endl << endl;
}