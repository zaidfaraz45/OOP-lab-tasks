
#include <iostream>
using namespace std;

class Employee
{   
    protected:
        string name;
        float salary;

    public:
        Employee(string n, float s) : name(n), salary(s) {}

        void display() const
        {
            cout << "Name of the employee: " << name << endl;
            cout << "Salary: $" << salary << endl;
        } 
};

class Manager : protected Employee
{
    float bonus;

    public:
        Manager (string n , float s, float b) : Employee(n, s), bonus(b) {}

        void display() const
        {
            Employee::display();
            cout << "Bonus: $" << bonus << endl;
        } 
};

int main()
{
    Manager manager("Zaid Faraz", 89056.2, 10198.4);
    manager.display();

    return 0;
}