#include <iostream>
using namespace std;

class Car  
{
    public:
        string brand;
        string model;
        float rentalPrice;
        bool availability;
        float totalRevenue;
        int registrationNumber;

        Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), availability(true), totalRevenue(0.0), registrationNumber(0) {}

        Car(string b, string m, float r, bool a, int n) : brand(b), model(m), rentalPrice(r), availability(a), totalRevenue(0.0), registrationNumber(n) {}

        void rentalRequest()
        {
            if (availability == false)
            {
                cout << "The car is already rented!" << endl;
            }
            else
            {
                availability = false;
            }
        }

        void applyDiscount(int days)
        {
            if (availability == true)
            {
                if (days > 5)
                {
                    rentalPrice *= 0.95;
                }
                else if (days > 10)
                {
                    rentalPrice *= 0.9;
                }
            }

            else
            {
                cout << "The car is already rented!" << endl;
            }
        }

        Car (Car &obj)
        {
            brand = obj.brand;
            model = obj.model;
            rentalPrice = obj.rentalPrice;
            availability = obj.availability;
            totalRevenue = obj.totalRevenue;
        }

        void updateRevenue(int days)
        {
            if (this->availability == false) 
            {
                this->totalRevenue += this->rentalPrice * days;  
                cout << "Total revenue is updated for " << this->brand << " " << this->model << ". Total revenue: " << this->totalRevenue << endl;
            }
            else
            {
                cout << "The car is not rented!" << endl;
            }
        }

        void display()
        {
            cout << "Registration Number: " << registrationNumber << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Rental price: " << rentalPrice << endl;
            if (availability == true)
            {
                cout << "The car is available!" << endl;
            }
            else
            {
                cout << "The car is not available!" << endl;
            }
            cout << "Total Revenue: " << totalRevenue << endl;
            cout << "-----------------------------------" << endl;
        }

        ~Car(){cout << endl << "The car is removed from memory" << endl;}
        
};

int main()
{
    Car car1("Toyota", "Corolla", 1000, true, 1234);
    car1.rentalRequest();

    car1.applyDiscount(7);

    car1.updateRevenue(10);

    car1.display();

    return 0;
}
