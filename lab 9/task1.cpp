#include <iostream>
using namespace std;

class Patient
{
    protected:
        string name;
        string id;

    public:
        Patient(string n, string ID): name(n), id(ID) {}
        virtual void displayTreatment() = 0;
        virtual void calculateCost() = 0;
};

class InPatient: public Patient
{
    public:
        InPatient(string n, string ID): Patient(n, ID) {}

        void displayTreatment() override
        {
            cout << "Treatment of:\n";
            cout << name << endl;
            cout << id << endl;
        }

        void calculateCost() override
        {
            cout << "Caculating cost for inpatient care\n\n";
        }
};

class OutPatient: public Patient
{
    public:
        OutPatient(string n, string ID): Patient(n, ID) {}

        void displayTreatment() override
        {
            cout << "Treatment of:\n";
            cout << name << endl;
            cout << id << endl;
        }

        void calculateCost() override
        {
            cout << "Caculating cost for outpatient care\n\n";
        }
};

int main()
{
    Patient* patient;

    patient = new InPatient("Zaid", "24k-0636");
    patient->displayTreatment();
    patient->calculateCost();

    delete patient;

    OutPatient outPatient("Ali", "24k-0800");
    patient = &outPatient;
    patient->displayTreatment();
    patient->calculateCost();

    return 0;
}