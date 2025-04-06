#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    private:
        int real;
        int imaginary;

    public:
        Complex(int r = 0, int i = 0): real(r), imaginary(i) {}

        Complex operator +(Complex c)
        {
            Complex complex;
            complex.real = real + c.real;
            complex.imaginary = imaginary + c.imaginary;

            return complex;
        }

        Complex operator /(Complex c)
        {
            Complex complex;
            complex.real = real / c.real;
            complex.imaginary = imaginary / c.imaginary;

            return complex;
        }

        Complex operator *(Complex c)
        {
            Complex complex;
            complex.real = real * c.real;
            complex.imaginary = imaginary * c.imaginary;

            return complex;
        }

        Complex operator -(Complex c)
        {
            Complex complex;
            complex.real = real - c.real;
            complex.imaginary = imaginary - c.imaginary;

            return complex;
        }

        friend ostream& operator <<(ostream& out, Complex& c);

        friend float magnitude(Complex c);
};

ostream& operator <<(ostream& out, Complex& c)
{
    out << c.real << " + " << c.imaginary << "i\n";
    return out;
}

float magnitude(Complex c)
{
    float magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
    return magnitude;
}

int main()
{
    Complex c1(12, 4);
    cout << c1; 
    cout << "Magnitude: " << magnitude(c1) << endl << endl;

    Complex c2(4, 2);
    cout << c2;
    cout << "Magnitude: " << magnitude(c2) << endl << endl;

    Complex c3, c4, c5, c6, c7;

    c3 = c1 + c2;
    cout << c3;
    cout << "Magnitude: " << magnitude(c3) << endl << endl;

    c4 = c1 - c2;
    cout << c4;
    cout << "Magnitude: " << magnitude(c4) << endl << endl;

    c5 = c1 * c2;
    cout << c5;
    cout << "Magnitude: " << magnitude(c5) << endl << endl;

    c6 = c1 / c2;
    cout << c6;
    cout << "Magnitude: " << magnitude(c6) << endl << endl;

    return 0;
}