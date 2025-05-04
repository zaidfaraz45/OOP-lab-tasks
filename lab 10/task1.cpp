#include <iostream>
#include <fstream>
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
    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}