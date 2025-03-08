#include <iostream>
using namespace std;

class AlarmSystem
{
    string securityLevel;

    public:
        AlarmSystem(string seclvl): securityLevel(seclvl) {} 
        void display() const
        {
            cout << "Security level of the alarm: " << securityLevel << endl;
        }

        ~AlarmSystem(){}
};

class SmartHome
{
    string name;
    AlarmSystem alarmSystem;

    public:
        SmartHome(string n, string alsys): name(n), alarmSystem(alsys) {}
        void display() const
        {
            cout << "\nSmart home name: " << name << endl;
            alarmSystem.display();
        }

        ~SmartHome(){}
};

int main()
{
    SmartHome smartHome1("CyberHive", "High");
    smartHome1.display();

    SmartHome smartHome2("Nebula Nest", "Medium");
    smartHome2.display();

    return 0;
}