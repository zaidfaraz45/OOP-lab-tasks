#include <iostream>
using namespace std;

class University
{
    string ID;
    string name;
    string *examScores;

    public:
        University(string id, string n, string *es) : ID(id), name(n) 
        {
            examScores = new string[3]; 
            for (int i = 0; i < 3; i++) 
            {
                examScores[i] = es[i];
            }
        }

        University(University &copy)
        {
            ID = copy.ID;
            name = copy.name;
            examScores = new string[3];
            for (int i = 0; i < 3; i++)
            {
                examScores[i] = copy.examScores[i];
            }
        }

        void display()
        {
            cout << "\nStudent ID: " << ID << endl;
            cout << "Student name: " << name << endl;
            cout << "Exam scores of the student: " << endl ;
            for (int i = 0; i < 3; i++)
            {
                cout << examScores[i] << endl;
            }
        }

        ~University() 
        {
            delete[] examScores; 
        }
};

int main()
{
    string scores[3] = {"15", "13", "45"};

    University university("24k-0636", "Zaid Faraz Syed", scores);
    university.display();

    University university1 = university;
    university1.display();

    return 0;
}