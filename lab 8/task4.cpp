#include <iostream>
using namespace std;

class InventoryManager; 

class Car
{
    private:
        string model;
        double price;

    public:
        Car()
        {
            model = "";
            price = 0.0;
        }

        Car(string m, double p): model(m), price(p) {}

        friend class InventoryManager;
        friend void comparePrice(Car c1, Car c2);
};

class InventoryManager
{
    public:
        void updatePrice(Car& c, double newPrice)
        {
            c.price = newPrice;
        }

        void display(Car c)
        {
            cout << "---------------------------" << endl;
            cout << "Car Model: " << c.model << endl;
            cout << "Price: $" << c.price << endl;
        }
};

void comparePrice(Car c1, Car c2)
{
    cout << "\nComparing Prices:\n";
    if (c1.price > c2.price)
    {
        cout << c1.model << " is more expensive than " << c2.model << "." << endl;
    }
    else if (c2.price > c1.price)
    {
        cout << c2.model << " is more expensive than " << c1.model << "." << endl;
    }
    else
    {
        cout << c1.model << " and " << c2.model << " are priced equally." << endl;
    }
}

int main()
{
    Car car1("Toyota Corolla", 28000);
    Car car2("Honda Civic", 27000);

    InventoryManager manager;

    manager.display(car1);
    manager.display(car2);

    manager.updatePrice(car2, 29000); 
    cout << "\nAfter updating Honda Civic price:\n";
    manager.display(car2);

    comparePrice(car1, car2);

    return 0;
}
