#include <iostream>
using namespace std;

struct Student
{
    string name;
    string rollnumber;
    int marks[3];
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n; 

    float totalMarks[n] = {0};
    float avgMarks[n];

    Student *students = new Student[n];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Enter the name of student " << i + 1 << ": ";
        cin >> ws;
        getline(cin, students[i].name);

        cout << "Enter the roll number of this student: ";
        cin >> ws;
        getline(cin, students[i].rollnumber);

        for (int j = 0; j < 3; j++)
        {    
            cout << "Enter the marks of this student for subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
            totalMarks[i] += students[i].marks[j];
        }
        
        avgMarks[i] = totalMarks[i] / 3;
    }

    cout << endl << "AVERAGE MARKS" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Student " << i + 1 << ":" << endl;
        cout << "Name - " << students[i].name << endl;
        cout << "Roll number - " << students[i].rollnumber << endl;
        cout << "Average marks - " << avgMarks[i] << endl;
    }
    
    delete[] (students);

    return 0;
}