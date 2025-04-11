#include <iostream>
using namespace std;

class Vector2D
{
    private:
        int x;
        int y;

    public:
        Vector2D()
        {
            x = 0;
            y = 0;
        }

        Vector2D(int X, int Y): x(X), y(Y) {}

        Vector2D operator +(Vector2D v)
        {
            Vector2D result;
            result.x = x + v.x;
            result.y = y + v.y;

            return result;
        }

        Vector2D operator -(Vector2D v)
        {
            Vector2D result;
            result.x = x - v.x;
            result.y = y - v.y;
            return result;
        }

        Vector2D operator *(int scalar)
        {
            Vector2D result;
            result.x = x * scalar;
            result.y = y * scalar;
            return result;
        }

        friend int dotProduct(Vector2D v1, Vector2D v2);

        friend ostream& operator <<(ostream& out, Vector2D v);  
};

int dotProduct(Vector2D v1, Vector2D v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator <<(ostream& out, Vector2D v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main()
{
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 3;

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    cout << "Sum: " << v3 << endl;
    cout << "Difference: " << v4 << endl;
    cout << "Scaled Vector 1 (x3): " << v5 << endl;
    cout << "Dot Product: " << dotProduct(v1, v2) << endl;

    return 0;
}