#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("sensor_log.txt", ios::out);

    if(!file.is_open())
    {
        cerr << "Unable to open file!\n";
        return 0;
    }

    file << "Sensor 1: 25.5 C\nSensor 2: 98.1 %RH \n";
    streampos position = file.tellp();

    cout << position << endl;

    return 0;
}