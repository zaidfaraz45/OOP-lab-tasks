#include <iostream>
using namespace std;

class Wallet
{
    string OwnerName;
    float totalBalance;     //total money in the account
    float transactionHistory;   //total money spent in transactions

    public:
        void input()
        {
            cout << "Enter the name of the wallet owner: ";
            getline(cin, OwnerName);

            cout << "Enter the total wallet balance: ";
            cin >> totalBalance;

            cout << "Enter money spent in transactions: ";
            cin >> transactionHistory;
        }

        void addMoney(float money)
        {
            totalBalance += money;
        }

        void spendMoney(float money)
        {
            transactionHistory += money;
        }

        void displayTransactions()
        {
            cout << "The total transaction is " << transactionHistory << ".";
        }
};

int main()
{
    Wallet wallet;

    wallet.input();

    return 0;
}