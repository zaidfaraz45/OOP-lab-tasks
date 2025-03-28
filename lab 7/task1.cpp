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
            }
        }

        virtual void turnOff()
        {
            if (status == false)
            {
                cout << "The device is already off!" << endl;
            }
            else
            {
                status = false;
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
            cout << "Status: " << (status) ? cout << "on" << endl : cout << "off" << endl; 
            cout << "Location: " << location << endl << endl;
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
            cout << "ID: " << deviceID << endl;
            cout << "Name: " << deviceName << endl;
            cout << "Status: " << (status) ? cout << "on" << endl : cout << "off" << endl; 
            cout << "Location: " << location << endl;
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

        float getStatus() override
        {
            return temperature;
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
            cout << powerConsumption << endl;
        }
};

int main()
{
    

    return 0;
}