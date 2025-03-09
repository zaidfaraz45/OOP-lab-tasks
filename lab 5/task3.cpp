#include <iostream>
using namespace std;

class Projects;

class Employees
{
    string name;
    string designation;

    public:
        Employees(string n, string des) : name(n), designation(des) {}
    
        void display() const
        {
            cout << "Name of the Employee: " << name << endl;
            cout << "Designation of the employee: " << designation << endl;
        }

        ~Employees(){}
};

class Projects
{
    string title;
    string deadline;
    Employees *employees[10];
    int employeeCount;

    public:
        Projects(string t, string d) : title(t), deadline(d), employeeCount(0) {}

        void addEmployees(Employees *emp)
        {
            if (employeeCount < 10)
            {
                employees[employeeCount] = emp;
                employeeCount++;
            }
            else
            {
                cout << "\nThis project is full!\n";
            }
        }

        void display () const
        {
            cout << "\nProject title: " << title << endl;
            cout << "Project deadline: " << deadline << endl;
            cout << "Employees involved in the project:\n";
            for (int i = 0; i < employeeCount; i++)
            {
                employees[i]->display();
            }
        }

        ~Projects(){}
};

int main()
{
    Employees employee1("Sam", "Manager");
    Employees employee2("Harry", "Director");

    Projects project1("OOP Project", "May 15, 2025");
    project1.addEmployees(&employee1);
    project1.addEmployees(&employee2);

    project1.display();

    return 0;
}