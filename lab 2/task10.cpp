#include <iostream>
using namespace std;

int main()
{   
    int x, y, z;

    cout << "Enter the length of x-coordinate: ";
    cin >> x;

    cout << "Enter the length of y-coordinate: ";
    cin >> y;

    cout << "Enter the length of z-coordinate: ";
    cin >> z;

    int ***array = new int**[x];
    for (int i = 0; i < x; i++)
    {
        array[i] = new int*[y];

        for (int j = 0; j < y; j++)
        {
            array[i][j] = new int[z];
        }
    }

    cout << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Enter the value at coordinate(" << i << ", " << j << ", " << k << "): ";
                cin >> array[i][j][k];
            }
        }
    }

    cout << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "The value at coordinate(" << i << ", " << j << ", " << k << "): " << array[i][j][k] << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
