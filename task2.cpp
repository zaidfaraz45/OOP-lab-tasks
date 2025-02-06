#include <iostream>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter number of rows for the first matrix: ";
    cin >> row;

    cout << "Enter number of columns for the first matrix: ";
    cin >> col;

    int **matrix1 = new int*[row];
    for (int i = 0; i < row; i++)
    {
        matrix1[i] = new int[col];
    }

    int **matrix2 = new int*[row];
    for (int i = 0; i < row; i++)
    {
        matrix2[i] = new int[col];
    }

    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter row " << i + 1 << " column " << j + 1 << " of matrix 1: ";
            cin >> matrix1[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter row " << i + 1 << " column " << j + 1 << " of matrix 2: ";
            cin >> matrix2[i][j];
        }
        cout << endl;
    }

    char operation;
    cout << "Addition (enter +) or Subtraction(enter -): ";
    cin >> operation;

    cout << "\nThe answer is:" << endl;
    if (operation == '+')
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << matrix1[i][j] + matrix2[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << matrix1[i][j] - matrix2[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < row; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < row; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;
}