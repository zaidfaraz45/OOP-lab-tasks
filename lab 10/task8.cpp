#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream outFile("config.txt", ios::out);

    if(!outFile.is_open())
    {
        cerr << "Unable to open file!\n";
        return 1;
    }

    outFile << "AAAAABBBBBCCCCC";

    outFile.close();

    fstream file("config.txt", ios::in | ios::out);

    if (!file.is_open())
    {
        cerr << "File could not be opened!\n";
        return 1;
    }

    file.seekp(5, ios::beg);

    file << "XXXXX";

    file.close();

    ifstream inFile("config.txt", ios::in);

    if (!inFile.is_open())
    {
        cerr << "File could not be opened!\n";
        return 1;
    }

    string fileData;

    getline(inFile, fileData);

    cout << fileData;

    inFile.close();

    return 0;
}