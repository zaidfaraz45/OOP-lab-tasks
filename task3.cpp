#include <iostream>
using namespace std;

struct Employee
{
    string name;
    int hoursWorked;
    float hourlyRate;
    float salary;
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *employees = new Employee[n]; 

    float salary[n];

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> ws;
        getline(cin, employees[i].name);

        cout << "Enter the hours worked by this employee: ";
        cin >> employees[i].hoursWorked;

        cout << "Enter the hourly rate of this employee: $";
        cin >> employees[i].hourlyRate;

        employees[i].salary = employees[i].hoursWorked * employees[i].hourlyRate;
        cout << endl;
    }

    cout << "EMPLOYEE SALARIES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << employees[i].name << ": $" << employees[i].salary << endl;
    }
    
    delete[] (employees);
    return 0;
}