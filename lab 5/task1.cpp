#include <iostream>
using namespace std;

class Apartment
{
    string Id;
    string address;
    string *ownerName;

    public:
        Apartment(string Id, string a, string owner): Id(Id), address(a) 
        {
            ownerName = new string(owner);
        }

        Apartment(const Apartment& copy) : Id (copy.Id), address(copy.address), ownerName(copy.ownerName) {}

        void display() const
        {
            cout << "\nApartment Id: " << Id << endl;
            cout << "Address: " << address << endl;
            cout << "Owner name: " << *ownerName << endl;
        }

        ~Apartment()
        {
            delete ownerName;
        }
};

int main()
{
    Apartment A1("A23424", "Karachi", "Zaid Faraz");
    A1.display();

    Apartment A2 = A1;

    A2.display();

    Apartment A3 = A1;

    A3.display();
    
    return 0;
}