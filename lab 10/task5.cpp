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

        if (type == "AutonomousCar")
        {
            size_t colonPosition = extraData.find(':');
            if (colonPosition != string::npos)
            {
                string numberStr = extraData.substr(colonPosition + 1);
                float softwareVersion = stof(numberStr);
                cout << "Software Version for ID " << id << ": " << softwareVersion << endl;
            }
            else
            {
                cout << "No colon found in ExtraData for AutonomousCar.\n";
            }
        }
        else if (type == "ElectricVehicle")
        {
            size_t colonPosistion = extraData.find(':');
            if (colonPosistion != string::npos)
            {
                string numberStr = extraData.substr(colonPosistion + 1);
                int batteryCapacity = stoi(numberStr);
                cout << "Battery Capacity for ID " << id << ": " << batteryCapacity << endl;
            }
            else
            {
                cout << "No colon found in ExtraData for ElectricVehicle.\n";
            }
        }
        else if (type == "HybridTruck")
        {
            size_t cargoPosition = extraData.find("Cargo:");
            size_t pipePosition = extraData.find('|');
            size_t batteryPosition = extraData.find("Battery:");

            if (cargoPosition != string::npos && pipePosition != string::npos && batteryPosition != string::npos)
            {
                string cargo = extraData.substr(cargoPosition + 6, pipePosition - (cargoPosition + 6));
                string battery = extraData.substr(batteryPosition + 8);

                int cargoNum = stoi(cargo);
                int batteryNum = stoi(battery);

                cout << "Cargo Capacity for ID " << id << ": " << cargo << endl;
                cout << "Battery Capacity for ID " << id << ": " << battery << endl;
            }
            else
            {
                cout << "Missing fields in ExtraData for HybridTruck!\n";
            }
        }
        else
        {
            cout << "Unknown vehicle type: " << type << endl;
        }
    }

    file.close();

    return 0;
}