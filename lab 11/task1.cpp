#include <iostream>
#include <stdexcept>
using namespace std;

class DimensionMismatchException : public exception
{
    string message;

public:
    DimensionMismatchException(int r1, int c1, int r2, int c2)
    {
        message = "DimensionMismatchException - Matrices must have same dimensions (2x2 vs 3x3)!\n";
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
    int rowsNum, colsNum;
    T **matrix;

public:
    Matrix() {}

    Matrix(int r, int c, T **m) : rowsNum(r), colsNum(c)
    {
        matrix = new T *[rowsNum];
        for (int i = 0; i < rowsNum; ++i)
        {
            matrix[i] = new T[colsNum];
            for (int j = 0; j < colsNum; ++j)
            {
                matrix[i][j] = m[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rowsNum; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix operator+(const Matrix &other) const
    {
        if (rowsNum != other.rowsNum || colsNum != other.colsNum)
        {
            throw DimensionMismatchException(rowsNum, colsNum, other.rowsNum, other.colsNum);
        }

        T **result = new T *[rowsNum];
        for (int i = 0; i < rowsNum; ++i)
        {
            result[i] = new T[colsNum];
            for (int j = 0; j < colsNum; ++j)
            {
                result[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        Matrix temp(rowsNum, colsNum, result);

        for (int i = 0; i < rowsNum; ++i)
        {
            delete[] result[i];
        }
        delete[] result;

        return temp;
    }

    void display() const
    {
        for (int i = 0; i < rowsNum; ++i)
        {
            for (int j = 0; j < colsNum; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    try
    {
        int **mat1 = new int *[2];
        for (int i = 0; i < 2; i++) {mat1[i] = new int[2];}

        mat1[0][0] = 3;
        mat1[0][1] = 2;
        mat1[1][0] = 7;
        mat1[1][1] = 6;

        int **mat2 = new int *[3];
        for (int i = 0; i < 3; i++) {mat2[i] = new int[3];}

        mat2[0][0] = 4;
        mat2[0][1] = -1;
        mat2[0][2] = 8;
        mat2[1][0] = 10;
        mat2[1][1] = 3;
        mat2[1][2] = 12;
        mat2[2][0] = 0;
        mat2[2][1] = 11;
        mat2[2][2] = 17;

        Matrix <int> matrix1(2, 2, mat1);
        Matrix <int> matrix2(3, 3, mat2);

        Matrix <int> result = matrix1 + matrix2;
        
        cout << "Matrix 1:\n";
        cout << "Matrix 2:\n";
        matrix1.display();
        cout << "Matrix 3:\n";
        matrix2.display();
        result.display();

        for (int i = 0; i < 2; i++)
        {
            delete[] mat1[i];
        }
        delete[] mat1;

        for (int i = 0; i < 2; i++)
        {
            delete[] mat2[i];
        }
        delete[] mat2;
    }

    catch (const DimensionMismatchException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
