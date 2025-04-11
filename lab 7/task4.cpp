#include <iostream>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
        string contactNumber;
        string address;

    public:
        Person(string n, int a, string c, string addr): name(n), age(a), contactNumber(c), address(addr) {}

        virtual void displayInfo()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Contact Number: " << contactNumber << endl;
            cout << "Address: " << address << endl;
        }

        virtual void updateInfo()
        {
            cout << "Updating info for " << name << "!" << endl;
        }
};

class Patient : public Person
{
    protected:
        string patientID;
        string medicalHistory;
        string doctorAssigned;

    public:
        Patient(string n, int a, string c, string addr, string pID, string mH, string dA): Person(n, a, c, addr), patientID(pID), medicalHistory(mH), doctorAssigned(dA) {}

        void displayInfo() override
        {
            Person::displayInfo();
            cout << "Patient ID: " << patientID << endl;
            cout << "Medical History: " << medicalHistory << endl;
            cout << "Doctor Assigned: " << doctorAssigned << endl << endl;
        }
};

class Doctor : public Person
{
    protected:
        string specialization;
        double consultationFee;
        string* patientsList;
        int numPatients;

    public:
        Doctor(string n, int a, string c, string addr, string spec, double fee, string* pList, int count): Person(n, a, c, addr), specialization(spec), consultationFee(fee), numPatients(count)
        {
            patientsList = new string[numPatients];
            for (int i = 0; i < numPatients; ++i)
            {
                patientsList[i] = pList[i];
            }
        }

        void displayInfo() override
        {
            Person::displayInfo();
            cout << "Specialization: " << specialization << endl;
            cout << "Consultation Fee: " << consultationFee << endl;
            cout << "Patients List: ";
            for (int i = 0; i < numPatients; ++i)
            {
                cout << patientsList[i] << " ";
            }
            cout << endl << endl;
        }

        ~Doctor()
        {
            delete[] patientsList;
        }
};

class Nurse : public Person
{
    protected:
        string assignedWard;
        string shiftTimings;

    public:
        Nurse(string n, int a, string c, string addr, string ward, string shift): Person(n, a, c, addr), assignedWard(ward), shiftTimings(shift) {}

        void displayInfo() override
        {
            Person::displayInfo();
            cout << "Assigned Ward: " << assignedWard << endl;
            cout << "Shift Timings: " << shiftTimings << endl << endl;
        }
};

class Administrator : public Person
{
    protected:
        string department;
        double salary;

    public:
        Administrator(string n, int a, string c, string addr, string dept, double s)
            : Person(n, a, c, addr), department(dept), salary(s) {}

        void updateInfo() override
        {
            cout << "Updating administrator data for " << name << " in department " << department << endl;
        }

        void displayInfo() override
        {
            Person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Salary: $" << salary << endl << endl;
        }
};

int main()
{
    string docPatients[] = {"P001", "P003"};

    Person* p1 = new Patient("Ayesha", 30, "0300-1234567", "Karachi", "P001", "Diabetes", "Dr. Kamal");
    Person* p2 = new Doctor("Dr. Kamal", 45, "0311-9988776", "Lahore", "Cardiologist", 2000.0, docPatients, 2);
    Person* p3 = new Nurse("Fatima", 28, "0333-4455667", "Multan", "Ward A", "Night");
    Person* p4 = new Administrator("Mr. Imran", 50, "0345-1122334", "Islamabad", "HR", 75000.0);

    p1->displayInfo();
    p2->displayInfo();
    p3->displayInfo();
    p4->displayInfo();

    p4->updateInfo();

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}