#include <iostream>
using namespace std;

class WeatherSensor
{
    public:
        virtual void readData() = 0;
        virtual void displayReport() = 0;
};

class Thermometer: public WeatherSensor
{
    public:
        void readData() override
        {
            cout << "Reading data for thermometer.....\n";
        }

        void displayReport() override
        {
            cout << "Displaying report for thermometer.....\n\n";
        }
};

class Barometer: public WeatherSensor
{
    public:
        void readData() override
        {
            cout << "Reading data for barometer.....\n";
        }

        void displayReport() override
        {
            cout << "Displaying report for barometer.....\n\n";
        }
};

int main()
{
    WeatherSensor* weatherSensor;
    weatherSensor = new Thermometer;
    weatherSensor->readData();
    weatherSensor->displayReport();

    delete weatherSensor;

    weatherSensor = new Barometer;
    weatherSensor->readData();
    weatherSensor->displayReport();

    delete weatherSensor;

    return 0;
}