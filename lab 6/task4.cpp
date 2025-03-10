#include <iostream>
using namespace std;

class Account
{
    protected:
        int accountNumber;
        float balance;
    
    public:
        Account(int aN, float b): accountNumber(aN), balance(b) {}

        void displayDetails()
        {
            cout << "\nAccount number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }

        ~Account(){}
};

class SavingsAccount: protected Account
{
    protected:
        float interestRate; 

    public:
        SavingsAccount(int aN, float b, float iR): Account(aN, b), interestRate(iR) {}

        void displayDetails()
        {
            Account::displayDetails();
            cout << "Interest rate: " << interestRate << "%" << endl;
        }

        ~SavingsAccount(){}
};

class CheckingAccount: protected Account
{
    protected:
        float overdraftLimit;
    
    public:
        CheckingAccount(int aN, float b, float oL) : Account(aN, b), overdraftLimit(oL) {}

        void displayDetails()
        {
            Account::displayDetails();
            cout << "Overdraft limit: $" << overdraftLimit << endl;
        } 

        ~CheckingAccount(){}
};

int main()
{
    SavingsAccount sA(123422432, 4003.4, 5);
    sA.displayDetails();

    CheckingAccount cA(1334233, 3442.23, 232.4);
    cA.displayDetails();

    return 0;
}