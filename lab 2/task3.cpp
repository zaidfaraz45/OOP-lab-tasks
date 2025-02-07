#include <iostream>
using namespace std;

struct Employee
{
    string name;
    int hoursWorked;
    float hourlyRate;
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
        cin.ignore();
        getline(cin, employees[i].name);

        cout << "Enter the hours worked by this employee: ";
        cin >> employees[i].hoursWorked;

        cout << "Enter the hourly rate of this employee: $";
        cin >> employees[i].hourlyRate;

        salary[i] = employees[i].hoursWorked * employees[i].hourlyRate;
        cout << endl;
    }

    cout << "EMPLOYEE SALARIES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << employees[i].name << ": $" << salary[i] << endl;
    }
    
    delete[] (employees);
    return 0;
}
