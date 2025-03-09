#include <iostream>
using namespace std;

class Doctor
{
    string name;
    string specialization;
    int experience;

    public:
        Doctor(string n, string spec, int xp): name(n), specialization(spec), experience(xp) {}

        void display()
        {
            cout << "Doctor name: " << name << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "Years of experience: " << experience << endl << endl;
        }

    ~Doctor(){}
};

class Hospital
{
    string name;
    Doctor *doctors[100];
    int docNum;

    public:
        Hospital(string n): name(n), docNum(0) {}

        void addDoctor(Doctor *doc)
        {
            if (docNum < 100)
            {
                doctors[docNum] = doc;
                docNum++;
            }
            else
            {
                cout << "The hospital is full!\n";
            }
        }

        void display() const
        {
            cout << "The name of the hospital: " << name << endl;
            cout << "The doctors working in the hospital:\n\n";
            for (int i = 0; i < docNum; i++)
            {
                doctors[i]->display();
            }
        }

        ~Hospital(){}
};

int main()
{
    Doctor doctor1("Dr. Adil", "Psychiatrist", 7);

    Doctor doctor2("Dr. Abdur Rehman", "Dermatologist", 10);

    Doctor doctor3("Dr. Ali Ahmed", "Cardiologist", 15);

    Hospital hospital("Aga Khan University Hospital");
    hospital.addDoctor(&doctor1);
    hospital.addDoctor(&doctor2);
    hospital.addDoctor(&doctor3);

    hospital.display();

    return 0;
}