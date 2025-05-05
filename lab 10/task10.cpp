#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream file("data_records.txt", ios::binary);

    if (!file.is_open()) 
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    string line;
    int targetLine = 3;
    int currentLine = 1;
    streampos position = 0;

    while (currentLine < targetLine && getline(file, line)) 
    {
        position = file.tellg();  
        currentLine++;
    }

    file.seekg(position, ios::beg);

    getline(file, line) ;
    
    cout << "Third record: " << line << endl;

    file.close();
    
    return 0;
}
