#include <iostream>
using namespace std;

class Manager;

class Account
{
    private:
        int accountNumber;
        float balance;

    public:
        Account(int aN, float b): accountNumber(aN), balance(b) {}

        friend Manager;
        friend void transferFunds(Account a1, Account a2, float fund);
};

void transferFunds(Account a1, Account a2, float fund)
{
    if (a1. balance >= fund)
    {
        a1.balance -= fund;
        a2.balance += fund;
    }

    else {cout << "Insufficient balance for transfer!" << endl;}
}

class Manager
{
    public:
        Account account;

        void display()
        {
            cout << "-------------------------------------------";
            cout << "ACCOUNT DETAILS\n";
            cout << "Account number: " << account.accountNumber << endl;
            cout << "Balance: $" << account.balance << endl;
        }

        void deposit(float balance)
        {
            account.balance += balance;
        }

        void withdraw(float balance)
        {
            if (balance <= account.balance) {account.balance -= balance;}            
            else {cout << "Not enough balance!" << endl;}
        }
};

int main()
{
    Account a1(14334, 1000);
    Account a2(13243, 2000);

    Manager m1(14334, 1000);
    m1.display();
}