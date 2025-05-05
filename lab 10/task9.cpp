#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file;
    file.open("large_log.txt", ios::in);

    if (!file.is_open())
    {
        cerr << "Unable to open file!";
        return 0;
    }

    string line;
    getline(file, line);
    cout << line;

    streampos position = file.tellg();
    cout << "\nPosition of pointer: " << position << endl << endl;

    getline(file, line);
    cout << line;

    position = file.tellg();
    cout << "\nPosition of pointer: " << position << endl << endl;

    file.close();

    return 0;
}