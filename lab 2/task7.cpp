#include <iostream>
using namespace std;

int main()
{
    int row1col2, col1row2;

    cout << "Enter the number of rows for matrix 1 / number of columns for matrix 2: ";
    cin >> row1col2;
    cout << "Enter the number of columns for matrix 1 / number of rows for matrix 2: ";
    cin >> col1row2;

    int **matrix1 = new int*[row1col2];
    for (int i = 0; i < row1col2; i++)
    {
        matrix1[i] = new int[col1row2];
    }

    int **matrix2 = new int*[col1row2];
    for (int i = 0; i < col1row2; i++)
    {
        matrix2[i] = new int[row1col2];
    }

    cout << endl;
    for (int i = 0; i < row1col2; i++)
    {
        for (int j = 0; j < col1row2; j++)
        {
            cout << "Enter row " << i + 1 << " column " << j + 1 << " of matrix 1: ";
            cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < col1row2; i++)
    {
        for (int j = 0; j < row1col2; j++)
        {
            cout << "Enter row " << i + 1 << " column " << j + 1 << " of matrix 2: ";
            cin >> matrix2[i][j];
        }
    }

    cout << "\nThe answer is:" << endl;
    for (int i = 0; i < row1col2; i++)
    {
        for (int j = 0; j < row1col2; j++)
        {
            int sum = 0;
            for (int k = 0; k < col1row2; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row1col2; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < col1row2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}
