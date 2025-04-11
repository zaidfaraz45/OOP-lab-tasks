#include <iostream>
using namespace std;

class MatrixHelper; 

class Matrix2x2
{
    private:
        int a, b, c, d; 

    public:
        Matrix2x2()
        {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
        }

        Matrix2x2(int A, int B, int C, int D): a(A), b(B), c(C), d(D) {}

        Matrix2x2 operator +(Matrix2x2 m)
        {
            return Matrix2x2(a + m.a, b + m.b, c + m.c, d + m.d);
        }

        Matrix2x2 operator -(Matrix2x2 m)
        {
            return Matrix2x2(a - m.a, b - m.b, c - m.c, d - m.d);
        }

        Matrix2x2 operator *(Matrix2x2 m)
        {
            return Matrix2x2(a * m.a + b * m.c, a * m.b + b * m.d,c * m.a + d * m.c,c * m.b + d * m.d);
        }

        friend int determinant(Matrix2x2 m);
        friend class MatrixHelper;
        friend ostream& operator <<(ostream& out, Matrix2x2 m);
};

int determinant(Matrix2x2 m)
{
    return (m.a * m.d - m.b * m.c);
}

class MatrixHelper
{
    public:
        void update(Matrix2x2& m, int row, int col, int value)
        {
            if (row == 0 && col == 0) {m.a = value;}
            else if (row == 0 && col == 1) {m.b = value;}
            else if (row == 1 && col == 0) {m.c = value;}
            else if (row == 1 && col == 1) {m.d = value;}
            else cout << "Invalid indices!" << endl;
        }
};

ostream& operator <<(ostream& out, Matrix2x2 m)
{
    out << "[" << m.a << " " << m.b << "]\n" << "[" << m.c << " " << m.d << "]" << endl;
    return out;
}

int main()
{
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "\nSum:\n" << sum;
    cout << "\nDifference:\n" << diff;
    cout << "\nProduct:\n" << prod;

    cout << "\nDeterminant of Matrix 1: " << determinant(m1) << endl;
    cout << "\nDeterminant of Matrix 2: " << determinant(m2) << endl;

    MatrixHelper helper;
    helper.update(m1, 0, 1, 9);

    cout << "\nMatrix 1 after update:\n" << m1;

    return 0;
}
