#include <iostream>
using namespace std;

class NegativeStockException: public exception {};

class OverCapacityException: public exception {};

template <typename T>
class InventoryItem
{
    T value;

    public:
        void set(T v)
        {
            if (v < 0)
            {
                throw NegativeStockException();
            }
            else if (v > 100)
            {
                throw OverCapacityException();
            }
            
            value = v;
        }
};

int main()
{
    try
    {
        InventoryItem <double> item1;
        cout << "Attempting to set stock to -5...\n";
        item1.set(-5);
    }
    catch(const NegativeStockException &e)
    {
        cerr << "Caught NegativeStockException - ";
        cerr << "what(): " << e.what() << endl;
    }

    try
    {
        InventoryItem <double> item2;
        cout << "Attempting to set stock to 120...\n";
        item2.set(130);
    }
    catch(const OverCapacityException &e)
    {
        cerr << "Caught OverCapacityException  - ";
        cerr << "what(): " << e.what() << endl;
    }

    return 0;
}