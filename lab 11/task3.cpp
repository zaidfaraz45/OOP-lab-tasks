#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidTemperatureException: public exception
{
    public:
        InvalidTemperatureException(double temperature) {}
};

template <typename T>
T convertToFahrenheit(T celsius)
{
    if (celsius < 273.15)
    {
        throw InvalidTemperatureException(celsius);
    }

    return (celsius * 9/5) + 32;
}

int main()
{
    try 
    {
        int celsius = -300;
        cout << "Attempting to convert " << celsius << "C\n";
        convertToFahrenheit(-300);
    }   
    catch(const InvalidTemperatureException &e)
    {
        cout << e.what();
    }

    return 0;
}