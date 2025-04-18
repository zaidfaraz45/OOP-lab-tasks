#include <iostream>
using namespace std;

class Shipment
{
    protected:
        string trackingNumber;
        double weight;
    
    public:
        Shipment(string n, double w): trackingNumber(n), weight(w) {}
        virtual void estimateDeliveryTime() = 0;
        virtual void showDetails() = 0;
};

class AirFreight: public Shipment
{
    public:
        AirFreight(string n, double w): Shipment(n, w) {}

        void estimateDeliveryTime() override
        {
            cout << "Estimating delivery time for Air Freight.....\n";
        }

        void showDetails() override
        {
            cout << "Details:\n";
            cout << trackingNumber << endl;
            cout << weight << " tonnes\n\n";
        }
};

class GroundShipment: public Shipment
{
    public:
        GroundShipment(string n, double w): Shipment(n, w) {}

        void estimateDeliveryTime() override
        {
            cout << "Estimating delivery time for Ground Shipment.....\n";
        }

        void showDetails() override
        {
            cout << "Details:\n";
            cout << trackingNumber << endl;
            cout << weight << " tonnes\n\n";
        }
};

int main()
{
    Shipment* shipment;
    
    AirFreight airFreight("1Z9999W99999999999", 300);
    shipment = &airFreight;
    shipment->estimateDeliveryTime();
    shipment->showDetails();

    GroundShipment groundShipment("T123-4567-8901", 1000);
    shipment = &groundShipment;
    shipment->estimateDeliveryTime();
    shipment->showDetails();

    return 0;
}