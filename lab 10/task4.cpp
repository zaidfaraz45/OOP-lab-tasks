#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string fileName = "vehicles.txt";
    ifstream file;
    file.open(fileName, ios::in);

    if (!file.is_open())
    {
        cerr << "File could not be opened!\n";
        return 1;
    }

    string line;
    getline(file, line);

    cout << line << endl;

    while(getline(file, line))
    {
        istringstream iss(line);
        string type, id, name, year, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        size_t colonPosition = extraData.find(':');
        if (colonPosition != string::npos)
        {
            string numberStr = extraData.substr(colonPosition + 1); 

            if (type == "AutonomousCar")
            {
                float softwareVersion = stof(numberStr);
                cout << "Software Version for ID " << id << ": " << softwareVersion << endl;
            }
            else if (type == "ElectricVehicle")
            {
                int batteryCapacity = stoi(numberStr);
                cout << "Battery Capacity for ID " << id << ": " << batteryCapacity << endl;
            }
        }
        else
        {
            cout << "No colon found in ExtraData. Skipping value extraction.\n";
        }
    }

    file.close();

    return 0;
}