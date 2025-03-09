#include <iostream>
using namespace std;

class Product
{
    string ID;
    string name;
    int quantity;

    public:
        Product(string id, string n, int q): ID(id), name(n), quantity(q) {}

        void display() const
        {
            cout << "Product ID: " << ID << endl;
            cout << "Product name: " << name << endl;
            cout << "Quantity in stock: " << quantity << endl;
        }
        
        string getID() const {return ID;}
        string getName() const {return name;}

        ~Product(){}
};

class Inventory
{
    Product *products[100];
    int num;

    public:
        Inventory(): num(0) {}

        void addProduct(string id, string name, int quantity)
        {
            if (num < 100)
            {
                products[num] = new Product(id, name, quantity);
                num++;
            }
            else
            {
                cout << "Inventory full!\n";
            }
        }

        void sort() 
        {
            for (int i = 0; i < num - 1; i++)
            {
                for (int j = 0; j < num - i - 1; j++)
                {
                    if (products[j]->getName() > products[j + 1]->getName())
                    {
                        Product *temp = products[j];
                        products[j] = products[j + 1];
                        products[j + 1] = temp;
                    }
                }
            }
        }

        void search(string id) const
        {
            bool found = false;
            for (int i = 0; i < num; i++)
            {
                if (products[i]->getID() == id)
                {
                    products[i]->display();
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Not found!" << endl;
            }
        }

        void display() const
        {
            for (int i = 0; i < num; i++)
            {
                products[i]->display();
            }
        }

        ~Inventory()
        {
            for (int i = 0; i < num; i++)
            {
                delete products[i];  
            }
        }
};

int main()
{
    Inventory inventory;

    inventory.addProduct("101", "Laptop", 50);
    inventory.addProduct("102", "Chair", 150);
    inventory.addProduct("103", "Apple", 200);
    inventory.addProduct("104", "Table", 20);

    cout << "\nBefore Sorting:\n";
    inventory.display();

    inventory.sort();

    cout << "\nAfter Sorting:\n";
    inventory.display();


    cout << "\nSearching for Product ID 102:\n";
    inventory.search("102");   

    cout << "\nSearching for Product ID 106:\n";
    inventory.search("106");   

    return 0;
}