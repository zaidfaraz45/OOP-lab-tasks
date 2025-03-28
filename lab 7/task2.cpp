#include <iostream>
using namespace std;

class Product
{
    protected:
        string productID;
        string productName;
        double price;
        int stockQuantity;

    public:
        Product(string id, string name, double p, int sQ) : productID(id), productName(name), price(p), stockQuantity(sQ) {}

        virtual void applyDiscount(double discount)
        {
            price -= discount;
        }

        virtual void calculateTotalPrice(int quantity)
        {

        }

        virtual void displayProductInfo()
        {
            cout << "Id: " << productID << endl;
            cout << "Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock quantity: " << stockQuantity << endl << endl;
        } 
};

class Electronics: public Product
{
    protected:
        int warrantyPeriod;
        string brand;

    public:
        Electronics(string id, string name, double p, int sQ, int wP, string b) : Product(id, name, p, sQ), warrantyPeriod(wP), brand(b) {}

        void displayProductInfo() override
        {
            cout << "Id: " << productID << endl;
            cout << "Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock quantity: " << stockQuantity << endl << endl;
            cout << "Warranty period: " << warrantyPeriod << endl;
            cout << "Brand: " << brand << endl << endl;
        }      
};

class Clothing: public Product 
{
    protected:
        float size;
        string color;
        string fabricMaterial;

    public:
        Clothing(string id, string name, double p, int sQ, int wP, string b, float s, string col, string fM) : Product(id, name, p, sQ), size(s), color(col), fabricMaterial(fM) {}

        void applyDiscount(double discount) override
        {

        }
};

class FoodItem: public Product
{
    protected:
        string expirationDate;
        int calories;

    public:
        FoodItem(string id, string name, double p, int sQ, int wP, string b, float s, string col, string fM, string eD, int cal) : Product(id, name, p, sQ), expirationDate(eD), calories(cal) {}

        void calculateTotalPrice(int quantity) override
        {

        }
};

class Book: public Product
{
    protected:
        string author;
        string genre;

    public:
        Book(string id, string name, double p, int sQ, int wP, string b, float s, string col, string fM, string eD, int cal, string a, string g) : Product(id, name, p, sQ), author, genre(g) {}

        void displayProductInfo() override
        {
            cout << "Id: " << productID << endl;
            cout << "Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock quantity: " << stockQuantity << endl;
            cout << "Author: " << author << endl;
            cout << "Genre: " << genre << endl << endl;
        }
};

int main()
{


    return 0;
}