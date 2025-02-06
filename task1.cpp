#include <iostream>
using namespace std;

struct book
{
    string title;
    string author;
    int year;
};

int main()
{
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cout << endl;

    book *Books = new book[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the title of book " << i + 1 << ": ";
        cin.ignore();
        getline(cin, Books[i].title);

        cout << "Enter the author of book " << i + 1 << ": ";
        cin.ignore();
        getline(cin, Books[i].author);

        cout << "Enter the year of book " << i + 1 << ": ";
        cin >> Books[i].year;
        cout << endl;
    }

    int year;
    cout << "Enter the year after which you want the books to be published: ";
    cin >> year;

    cout << endl << "BOOKS AFTER " << year << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (Books[i].year >= year)
        {
            cout << Books[i]. title << " By " << Books[i].author << " published in " << Books[i].year << endl;
        }
    }

    delete[](Books);

    return 0;
}