#include <iostream>
using namespace std;

class Device
{
    protected:    
        string deviceID;
        string deviceName;
        bool status;
        string location;

    public:
        Device(string id, string name, bool stat, string loc): deviceID(id), deviceName(name), status(stat), location(loc) {}

        virtual void turnOn()
        {
            if (status == true)
            {
                cout << "The device is already on!" << endl;
            }
            else
            {
                status = true;
                cout << "The device has been turned on!" << endl;
            }
        }

        virtual void turnOff()
        {
            if (status == false)
            {
                cout << deviceName << " is already off!" << endl;
            }
            else
            {
                status = false;
                cout << deviceName << " has been turned off." << endl;
            }
        }

        virtual bool getStatus()
        {
            return status;
        }

        virtual void displayInfo()
        {
            cout << "ID: " << deviceID << endl;
            cout << "Name: " << deviceName << endl;
            cout << "Status: " << (status ? "on" : "off") << endl; 
            cout << "Location: " << location << endl;
        }
};

class Light: public Device
{
    protected:
        int brightnessLevel;
        string colorMode;
    
    public:
        Light(string id, string name, bool stat, string loc, int brightLvl, string cM): Device(id, name, stat, loc), brightnessLevel(brightLvl), colorMode(cM) {}

        void displayInfo() override
        {
            Device::displayInfo();
            cout << "Brightness level: " << brightnessLevel << endl;
            cout << "Color mode: " << colorMode << endl << endl;
        }        
};

class Thermostat: public Device
{
    protected:
        float temperature;
        string tempMode;
        float targetTemp;
    
    public:
        Thermostat(string id, string name, bool stat, string loc, float t, string tM, float tT): Device(id, name, stat, loc), temperature(t), tempMode(tM), targetTemp(tT) {}

        float getTemperature() 
        {
            return temperature;
        }

        void displayInfo() override
        {
            Device::displayInfo();
            cout << "Current temperature: " << temperature << " degress celsius" << endl;
            cout << "Temperature mode: " << tempMode << endl;
            cout << "Target temperature: " << targetTemp << " degress celsius" << endl << endl;
        }
};

class SecurityCamera: public Device
{
    protected:
        string resolution;
        bool recordingStatus;
        bool nightVisionEnabled;

    public:
        SecurityCamera(string id, string name, bool stat, string loc, string res, bool rS, bool nVE): Device(id, name, stat, loc), resolution(res), recordingStatus(rS), nightVisionEnabled(nVE) {}

        void turnOn() override
        {
            recordingStatus = true;
            cout << deviceName << " is recording!" << endl;
        }

         void displayInfo() override
        {
            Device::displayInfo();
            cout << "Resolution: " << resolution << endl;
            cout << "Recording status: " << (recordingStatus ? "Enabled" : "Disabled") << endl;
            cout << "Night Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << endl << endl;
        }
};

class SmartPlug: public Device
{
    protected:
        int powerConsumption;
        float timerSetting;
    
    public:
        SmartPlug(string id, string name, bool stat, string loc, int pC, float tS): Device(id, name, stat, loc), powerConsumption(pC), timerSetting(tS) {}

        void turnOff() override
        {
            if (status == true)
            {
                status = false;
                cout << deviceName << "has been turned off!" << endl;
                cout << "Power Consumption: " << powerConsumption << endl;
            }
            else
            {
                cout << deviceName << "is already off!" << endl;
            }
        }

        void displayInfo() override
        {
            Device::displayInfo();
            cout << "Power consumption: " << powerConsumption << "W" << endl;
            cout << "Timer setting: " << timerSetting << " minutes" << endl << endl;
        }
};

int main()
{
    Device* device;

    Light light("0132", "Living Room Light", false, "Home", 9, "Warm White");
    Thermostat thermostat("0245", "Smart Thermostat", true, "Office", 22.5, "Cooling", 24.0);
    SecurityCamera camera("0356", "Front Door Camera", false, "Entrance", "1080p", false, true);
    SmartPlug plug("0467", "Smart Plug", true, "Kitchen", 50, 30.0);

    device = &light;
    device->displayInfo();  
    device->turnOn();
    device->displayInfo();

    device = &thermostat;
    device->displayInfo();

    device = &camera;
    device->displayInfo();
    device->turnOn();  
    device->displayInfo();

    device = &plug;
    device->displayInfo();
    device->turnOff();
    device->displayInfo();
    
    return 0;
}
