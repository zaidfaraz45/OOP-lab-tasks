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
        return 0;
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
        
        int yearNum = stoi(year);

        cout << "---------------------------------------\n";    
        cout << "Type ->" << type << endl;
        cout << "ID ->" << id << endl;
        cout << "Name ->" << name << endl;
        cout << "Year -> " << yearNum << endl;
        cout << "ExtraData ->" << extraData << endl;
        cout << "Certification ->" << certification << endl;
    }

    file.close();

    return 0;
}