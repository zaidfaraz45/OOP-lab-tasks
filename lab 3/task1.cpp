#include <iostream>
#include <string>
using namespace std;

class Wallet
{
    string OwnerName;
    double totalBalance = 0;     
    int transactionNum = 0;
    double *transactionHistory = new double[transactionNum];   

    public:
        void inputName()
        {
            cout << "Enter the name of the wallet owner: ";
            getline(cin, OwnerName);
        }

        void addMoney(float money)
        {
            totalBalance += money;
        }

        void spendMoney(float money)
        {
            if (money <= totalBalance)
            {
                transactionHistory[transactionNum] += money;
                transactionNum++;
            }
            else
            {
                cout << "Not enough money!";
            }
        }

        void displayTransactions()
        {
            cout << "\nTransaction history of " << OwnerName << ":" << endl; 
            for (int i = 0; i < transactionNum; i++)
            {
                cout << "Rs. " << transactionHistory[i] << endl;
            } 
        }

        void deallocateMemory()
        {
            delete[] transactionHistory;
        }
};

int main()
{
    Wallet wallet;

    wallet.inputName();
    wallet.addMoney(100000);
    wallet.spendMoney(1024.53);
    wallet.spendMoney(200);
    wallet.spendMoney(20022.21);
    wallet.spendMoney(3000);
    wallet.spendMoney(13224);
    wallet.spendMoney(2342);
    wallet.spendMoney(1000);
    wallet.spendMoney(2322.2);
    wallet.spendMoney(2223);
    wallet.spendMoney(23222.2);
    wallet.spendMoney(100);
    wallet.spendMoney(500000);
    wallet.displayTransactions();

    wallet.deallocateMemory();

    return 0;
}