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

        Car()
        {
            brand = "Unknown";
            model = "Generic";
            rentalPrice = 0.0;
            availability = true;
            totalRevenue = 0.0;
        }

        Car(string b, string m, float r, bool a)
        {
            brand = b;
            model = m;
            rentalPrice = r;
            availability = a;
        }

        void rentalRequest()
        {
            if (availability == false)
            {
                cout << "The car is already rented" << endl;
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
                cout << "The car is already rented.";
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
            if (this->availability == true) 
            {
                this->totalRevenue += this->rentalPrice * days;  
                cout << "Total revenue is updated for " << this->brand << " " << this->model << ". Total revenue: " << this->totalRevenue << endl;
            }
            else
            {
                cout << "The car is not available!" << endl;
            }
        }

        ~Car(){}
};

int main()
{
    Car car1("Toyota", "Corolla", 1000, true);
    Car car2;
    car2 = car1;

    return 0;
}
