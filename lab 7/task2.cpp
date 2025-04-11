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
        Product() {}
        Product(string id, string name, double p, int sQ): productID(id), productName(name), price(p), stockQuantity(sQ) {}

        virtual void applyDiscount(double discount) 
        {
            price -= discount;
        }

        virtual float calculateTotalPrice(int quantity) 
        {
            return quantity * price;
        }

        virtual void displayProductInfo() 
        {
            cout << "Id: " << productID << endl;
            cout << "Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock quantity: " << stockQuantity << endl;
        }

        double operator +(const Product& obj) 
        {
            return this->price + obj.price;
        }

        friend ostream& operator <<(ostream& os, const Product& obj) 
        {
            os << "Product ID: " << obj.productID << "\nProduct Name: " << obj.productName << "\nPrice: " << obj.price << "\nStock Quantity: " << obj.stockQuantity << endl;
            return os;
        }

        virtual ~Product() {}
};

class Electronics : public Product 
{
    protected:
        int warrantyPeriod;
        string brand;

    public:
        Electronics(string id, string name, double p, int sQ, int wP, string b): Product(id, name, p, sQ), warrantyPeriod(wP), brand(b) {}

        void displayProductInfo() override 
        {
            Product::displayProductInfo();
            cout << "Warranty period: " << warrantyPeriod << " months" << endl;
            cout << "Brand: " << brand << endl << endl;
        }
};

class Clothing : public Product 
{
    protected:
        float size;
        string color;
        string fabricMaterial;

    public:
        Clothing(string id, string name, double p, int sQ, float s, string col, string fM): Product(id, name, p, sQ), size(s), color(col), fabricMaterial(fM) {}

        void applyDiscount(double discount) override 
        {
            price -= 2 * discount;
        }

        void displayProductInfo() override 
        {
            Product::displayProductInfo();
            cout << "Size: " << size << endl;
            cout << "Color: " << color << endl;
            cout << "Fabric: " << fabricMaterial << endl << endl;
        }
};

class FoodItem : public Product 
{
    protected:
        string expirationDate;
        int calories;

    public:
        FoodItem(string id, string name, double p, int sQ, string eD, int cal): Product(id, name, p, sQ), expirationDate(eD), calories(cal) {}

        float calculateTotalPrice(int quantity) override 
        {
            float total = quantity * price;
            if (quantity >= 10) {total *= 0.9;}
            return total;
        }

        void displayProductInfo() override 
        {
            Product::displayProductInfo();
            cout << "Expiration Date: " << expirationDate << endl; 
            cout << "Calories: " << calories << endl << endl;
        }
};

class Book : public Product 
{
    protected:
        string author;
        string genre;

    public:
        Book(string id, string name, double p, int sQ, string a, string g): Product(id, name, p, sQ), author(a), genre(g) {}

        void displayProductInfo() override 
        {
            Product::displayProductInfo();
            cout << "Author: " << author << endl;
            cout << "Genre: " << genre << endl << endl;
        }
};

int main() 
{
    Product* p1 = new Electronics("E101", "Laptop", 1200.0, 5, 24, "Dell");
    Product* p2 = new Clothing("C202", "Shirt", 30.0, 20, 42, "Blue", "Cotton");
    Product* p3 = new FoodItem("F303", "Chocolate", 2.5, 100, "2025-06-01", 250);
    Product* p4 = new Book("B404", "C++ Guide", 50.0, 10, "Bjarne Stroustrup", "Programming");

    p1->displayProductInfo();

    p2->applyDiscount(5);
    p2->displayProductInfo();

    p3->displayProductInfo();
    cout << "Bulk food price for 12 items: " << p3->calculateTotalPrice(12) << endl << endl;

    p4->displayProductInfo();

    double totalBulkPrice = *p1 + *p4;  
    cout << "Total price of Laptop and C++ Guide: " << totalBulkPrice << endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}