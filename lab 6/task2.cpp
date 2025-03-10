#include <iostream>
using namespace std;

class Vehicle
{
    protected:
        string brand;
        int speed;

    public:
        Vehicle(string b, int s) : brand(b), speed(s) {}

        void displayDetails()
        {
            cout << "\nVehicle brand: " << brand << endl;
            cout << "Vehicle speed: " << speed << " km/h" << endl; 
        }

        ~Vehicle(){}
};

class Car : protected Vehicle
{   
    protected:
        int seats;

    public:
        Car(int s, string b, int spd) : seats(s), Vehicle(b, spd) {}

        void displayDetails()
        {
            Vehicle::displayDetails();
            cout << "Number of seats: " << seats << endl;
        }       

        ~Car(){}
};

class ElectricCar : protected Car
{
    protected:
        int batteryLife;
    
    public:
        ElectricCar(int bL, int s, string b, int spd) : batteryLife(bL), Car(s, b, spd) {}

        void displayDetails()
        {
            Car::displayDetails();
            cout << "Battery life: " << batteryLife << " hours" << endl;
        }

        ~ElectricCar(){}
};

int main()
{
    ElectricCar ec(12, 7, "Tesla", 300);
    ec.displayDetails();

    return 0;
}