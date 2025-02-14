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
};
