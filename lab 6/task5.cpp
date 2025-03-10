#include <iostream>
using namespace std;

class Device
{
    protected:
        int deviceID;
        bool status;
    
    public:
        Device(int id, bool s): deviceID(id), status(s) {}

        virtual void displayDetails()
        {
            cout << "\nDevice ID: " << deviceID << endl;
            cout << "Status: " << (status ? "Working" : "Not working") << endl;
        }

        virtual ~Device(){}
};

class SmartPhone : virtual protected Device
{
    protected:
        float screenSize;
    
    public:
        SmartPhone(int id, bool s, float ss) : Device(id, s), screenSize(ss) {}

        void displayDetails() override
        {
            Device::displayDetails();
            cout << "Screen size: " << " inches" << endl;
        }

        ~SmartPhone(){}
};

class SmartWatch: virtual protected Device
{   
    protected:
        bool heartRateMonitor;

    public:
        SmartWatch(int id, bool s, bool hRM) : Device(id, s), heartRateMonitor(hRM) {}

        void displayDetails() override
        {
            Device::displayDetails();
            cout << "Monitor heart rate: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
        }

        ~SmartWatch(){}
};

class SmartWearable : protected SmartPhone, protected SmartWatch
{
    protected:
        int stepCounter;
    
    public:
        SmartWearable(int id, bool s, float ss, bool hRM, int sC): Device(id, s), SmartPhone(id, s, ss), SmartWatch(id, s, hRM), stepCounter(sC) {}

        void displayDetails() override
        {
            Device::displayDetails(); 

            cout << "Screen size: " << screenSize << " inches" << endl;
            cout << "Monitor heart rate: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
            cout << "Number of steps: " << stepCounter << endl;
        }

        ~SmartWearable(){}

};

int main()
{
    SmartWearable sw(234, true, 7.1, true, 10000);
    sw.displayDetails();

    return 0;
}