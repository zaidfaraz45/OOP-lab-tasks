#include <iostream>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    
    public:
        Person(string n, int a) : name(n), age(a) {}

        virtual void displayDetails()
        {
            cout << "\nName: " << name << endl;
            cout << "Age: " << age << endl;
        }

        ~Person(){}
};

class Teacher : virtual protected Person
{
    protected:
        string subject;
    
    public:
        Teacher(string n, int a, string s) : Person(n, a), subject(s) {}

        void displayDetails() override
        {
            Person::displayDetails();
            cout << "Subject: " << subject << endl;
        }

        ~Teacher(){}
};

class Researcher : virtual protected Person
{
    protected:
        string researchArea;
    
    public:
        Researcher(string n, int a, string rA) : Person(n, a), researchArea(rA) {}

        void displayDetails() override
        {
            Person::displayDetails();
            cout << "Research area: " << researchArea << endl;
        }

        ~Researcher(){}
};

class Professor : protected Teacher, protected Researcher
{
    protected:
        int publications;

    public:
        Professor(string n, int a, string s, string rA, int p): Person(n, a), Teacher(n, a, s), Researcher(n, a, rA), publications(p) {}

        void displayDetails() override
        {
            Person::displayDetails();
            cout << "Subject: " << subject << endl;
            cout << "Research Area: " << researchArea << endl;
            cout << "Publications: " << publications << endl;
        }
};

int main()
{
    Professor professor("Talha Shahid", 25, "OOP", "MAchine Learning", 3);
    professor.displayDetails();   

    return 0;
}