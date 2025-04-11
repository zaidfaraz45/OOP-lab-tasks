#include <iostream>
using namespace std;

class Manager;

class Account
{
    private:
        int accountNumber;
        float balance;

    public:
        Account(int aN, float b) : accountNumber(aN), balance(b) {}

        friend class Manager;
        friend void transferFunds(Account& a1, Account& a2, float fund);
    };

    void transferFunds(Account& a1, Account& a2, float fund)
    {
        if (a1.balance >= fund)
        {
            a1.balance -= fund;
            a2.balance += fund;
            cout << "Transferred $" << fund << " from Account " << a1.accountNumber << " to Account " << a2.accountNumber << "!" << endl;
        }
        else
        {
            cout << "Insufficient balance in Account " << a1.accountNumber << " for transfer!" << endl;
        }
}

class Manager
{
    public:
        void display(Account a)
        {
            cout << "-------------------------------------------" << endl;
            cout << "ACCOUNT DETAILS\n";
            cout << "Account number: " << a.accountNumber << endl;
            cout << "Balance: $" << a.balance << endl;
        }

        void deposit(Account& a, float amount)
        {
            a.balance += amount;
            cout << "Deposited $" << amount << " to Account " << a.accountNumber << "!" << endl;
        }

        void withdraw(Account& a, float amount)
        {
            if (amount <= a.balance)
            {
                a.balance -= amount;
                cout << "Withdrew $" << amount << " from Account " << a.accountNumber << "!" << endl;
            }
            else
            {
                cout << "Not enough balance in Account " << a.accountNumber << "!" << endl;
            }
        }
};

int main()
{
    Account a1(14334, 1000);
    Account a2(13243, 2000);

    Manager m;

    m.display(a1);
    m.display(a2);

    m.deposit(a1, 500);
    m.withdraw(a2, 1200);

    m.display(a1);
    m.display(a2);

    transferFunds(a1, a2, 700);

    m.display(a1);
    m.display(a2);

    return 0;
}
