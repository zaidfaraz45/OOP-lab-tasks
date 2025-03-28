#include <iostream>
using namespace std;

class Car  
{
    public:
        string brand;
        string model;
        float rentalPrice;
        bool availability;

        Car()
        {
            brand = "Unknown";
            model = "Generic";
            rentalPrice = 0.0;
            availability = true;
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
        }

        ~Car(){cout << endl << "The car is removed from memory" << endl;}
};

int main()
{
    Car car1("Toyota", "Corolla", 1000, true);
    Car car2;
    car2 = car1;

    return 0;
}
