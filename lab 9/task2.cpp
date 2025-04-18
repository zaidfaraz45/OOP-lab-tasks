#include <iostream>
using namespace std;

class MenuItem
{
    protected:
        string dishName;
        double price;

    public:
        MenuItem(string n, double p): dishName(n), price(p) {}
        virtual void showDetails() = 0;
        virtual void prepare() = 0;
};

class Appteizer: public MenuItem
{
    public:
        Appteizer(string n, double p): MenuItem(n, p) {}

        void showDetails() override
        {
            cout << "Appetizer Details:\n";
            cout << dishName << endl;
            cout << "Rs. " << price << endl;
        }

        void prepare() override
        {
            cout << "Preparing Appetizer.....\n\n";
        }
};

class MainCourse: public MenuItem
{
    public:
        MainCourse(string n, double p): MenuItem(n, p) {}

        void showDetails() override
        {
            cout << "Main Course Details:\n";
            cout << dishName << endl;
            cout << "Rs. " << price << endl;
        }

        void prepare() override
        {
            cout << "Preparing Main Course.....\n\n";
        }
};

int main()
{
    MenuItem *menuItem;

    menuItem = new Appteizer("Aloo Samosa", 50);     
    menuItem->showDetails();
    menuItem->prepare();

    delete menuItem;

    MainCourse mainCourse("Chicken Biryani", 200);
    menuItem = &mainCourse;
    menuItem->showDetails();
    menuItem->prepare();
    
    return 0;
}