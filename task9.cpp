#include <iostream>
using namespace std;

struct Product
{
    string productID;
    string name;
    int quantity;
    float price;
};

int main()
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product *products = new Product[n];
    float totalValue[n];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Enter the productID of product " << i + 1 << ": ";
        cin >> products[i].productID;

        cout << "Enter the name of this product: ";
        cin.ignore();
        getline(cin, products[i].name);

        cout << "Enter the quantity of this product: ";
        cin >> products[i].quantity;

        cout << "Enter the price of this product: $";
        cin >> products[i].price;

        totalValue[i] = float(products[i].quantity) * products[i].price;

        cout << "Total value: $" << totalValue[i] << endl;
    }

    delete[] (products);

    return 0;
}