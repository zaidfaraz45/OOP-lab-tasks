#include <iostream>
using namespace std;

class Car
{
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;
    double fuelPerDistance;
    
    public:
        void input()
        {
            cout << "Enter brand of the car: ";
            cin >> brand;

            cout << "Enter the model of the car: ";
            cin >> model;

            cout << "Enter the fuel capacity of this car(in litres): ";
            cin >> fuelCapacity;

            cout << "Enter the fuel(litres) this car consumes for every kilometre: ";
            cin >> fuelPerDistance;

            cout << "Enter current fuel level: ";
            cin >> currentFuelLevel;
        }

        void driveCar(double distance)
        {
            currentFuelLevel -= distance * fuelPerDistance;
        }

        void refuelTank(double fuel)
        {
            currentFuelLevel += fuel;
        }

        void checkFuelStatus()
        {
            cout << endl << "The current fuel level in your " << brand << " " << model << " is " << currentFuelLevel << " litres." << endl;
        }
    
};

 int main()
 {
    Car car;

    car.input();
    car.checkFuelStatus();

    car.driveCar(2);
    car.checkFuelStatus();

    car.refuelTank(23);
    car.checkFuelStatus();

    return 0;
 }