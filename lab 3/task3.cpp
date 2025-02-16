#include <iostream>
using namespace std;

class Library 
{
    int listNum = 0;
    string *bookList = nullptr;
    int borrowedNum = 0;
    string *borrowedBooks = nullptr;
    int availableNum = 0;
    string *availableBooks = nullptr;

    public:
        void addBooks(string book)
        {
            string *newBookList = new string[listNum + 1];
            string *newAvailableBooks = new string[availableNum + 1];

            for (int i = 0; i < listNum; i++) 
            {newBookList[i] = bookList[i];}
            for (int i = 0; i < availableNum; i++) 
            {newAvailableBooks[i] = availableBooks[i];}

            newBookList[listNum] = book;
            newAvailableBooks[availableNum] = book;

            delete[] bookList;
            delete[] availableBooks;

            bookList = newBookList;
            availableBooks = newAvailableBooks;

            listNum++;
            availableNum++;
        }

        void lendBooks(string book)
        {
            bool found = false;  

            for (int i = 0; i < availableNum; i++)
            {
                if (availableBooks[i] == book)
                {
                    string *newBorrowedBooks = new string[borrowedNum + 1];
                    for (int j = 0; j < borrowedNum; j++) 
                    {newBorrowedBooks[j] = borrowedBooks[j];}
                    
                    newBorrowedBooks[borrowedNum] = book;
                    
                    delete[] borrowedBooks;
                    borrowedBooks = newBorrowedBooks;
                    borrowedNum++;

                    for (int j = i; j < availableNum - 1; j++)
                    {availableBooks[j] = availableBooks[j + 1];}
                    availableNum--; 

                    found = true;
                    break; 
                }
            }

            if (!found)  
            {cout << "Book not available!" << endl;}
        }

        void returnBook(string book)
        {
            bool found = false;  

            for (int i = 0; i < borrowedNum; i++)
            {
                if (borrowedBooks[i] == book)
                {
                    string *newAvailableBooks = new string[availableNum + 1];
                    for (int j = 0; j < availableNum; j++) 
                    {
                        newAvailableBooks[j] = availableBooks[j];
                    }
                    newAvailableBooks[availableNum] = book;
        
                    delete[] availableBooks;
                    availableBooks = newAvailableBooks;
                    availableNum++;
        
                    for (int j = i; j < borrowedNum - 1; j++)
                    {
                        borrowedBooks[j] = borrowedBooks[j + 1];
                    }
                    borrowedNum--;
        
                    found = true;
                    break; 
                }
            }

            if (!found)  
            {cout << "Book not found in borrowed books!" << endl;}    
        }        

        void display()
        {
            cout << endl << "List of all books:" << endl;
            for (int i = 0; i < listNum; i++) 
            {cout << bookList[i] << endl;}

            cout << endl << "List of available books:" << endl;
            for (int i = 0; i < availableNum; i++)
            {cout << availableBooks[i] << endl;}

            cout << endl << "List of borrowed books:" << endl;
            for (int i = 0; i < borrowedNum; i++)
            {cout << borrowedBooks[i] << endl;}
        }

        void deallocateMemory()
        {
            delete[] bookList;
            delete[] borrowedBooks;
            delete[] availableBooks;
        }
};

int main()
{
    Library library;
    
    library.addBooks("Clean Code");
    library.addBooks("The Pragmatic Programmer");
    library.addBooks("Design Patterns");
    library.addBooks("Introduction to the Theory of Computation");
    library.addBooks("Pattern Recognition and Machine Learning");
    library.addBooks("Dune");
    library.addBooks("The Hobbit");
    library.addBooks("Neuromancer");
    library.addBooks("Atomic Habits");
    library.addBooks("Deep Work");

    library.display();

    library.lendBooks("Deep Work"); 
    library.display();
    
    library.lendBooks("Deep Work");  
    library.display();

    library.returnBook("Deep Work");
    library.display();

    library.deallocateMemory();  

    return 0;
}
