#include <iostream>
using namespace std;

int main()
{
    size_t size;
    cout << "Enter the size of an array: ";
    cin >> size;

    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter ineteger " << i + 1 << ": ";
        cin >> *(array + i);
    }

    int sum = 0;
    cout << endl << "Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << endl;
        sum += *(array + i);
    }

    cout << endl << "Sum of the array is " << sum << "." << endl;

    delete[] (array);

    return 0;
}