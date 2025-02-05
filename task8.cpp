#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *array = new int[n];

    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << endl << "Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }

    delete[] array;

    return 0;
}