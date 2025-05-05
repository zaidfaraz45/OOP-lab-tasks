#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem
{
    int inventoryId;
    char itemName[20];

    public:
        InventoryItem(int id, const char name[20]): inventoryId(id)
        {
            strncpy(itemName, name, 19);
            itemName[19] = '\0'; 
        }

        InventoryItem() {} 

        void display() 
        {
            cout << "Item ID: " << inventoryId << endl;
            cout << "Item Name: " << itemName << endl;
        }
};

int main()
{
    InventoryItem item(1263, "Hammer");

    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile)
    {
        cerr << "Unable to write to file!";
        return 1;
    }

    outFile.write((char*)&item, sizeof(item));
    outFile.close();

    InventoryItem loadedItem;
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Unable to read from file!";
        return 1;
    }

    inFile.read((char*)&loadedItem, sizeof(loadedItem));
    inFile.close();

    loadedItem.display();

    return 0;
}
