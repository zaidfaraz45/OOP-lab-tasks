#include <iostream>
#include <stdexcept>
using namespace std;

class DatabaseException : public exception
{
protected:
    string message;

public:
    DatabaseException()
    {
        message = "A database error occurred.";
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class ConnectionFailedException : public DatabaseException
{
public:
    ConnectionFailedException()
    {
        message = "A database error occurred.";
    }
};

class QueryTimeoutException : public DatabaseException
{
public:
    QueryTimeoutException(int timeout)
    {
        message = "A database error occurred.";
    }
};

template <typename T>
class DatabaseConnector
{
    T dbName;

public:
    void connect(T dbName)
    {
        if (dbName == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        else if (dbName == "slow_db")
        {
            throw QueryTimeoutException(30);
        }
        else
        {
            cout << "Connected to " << dbName << " successfully.\n";
        }
    }
};

int main()
{
    DatabaseConnector<string> db;

    try
    {
        cout << "Attempting to connect to invalid_db..." << endl;
        db.connect("invalid_db");
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException - ";
        cout << "what(): " << e.what() << endl;
    }

    try
    {
        cout << "\nAttempting to connect to slow_db..." << endl;
        db.connect("slow_db");
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException - ";
        cout << "what(): " << e.what() << endl;
    }

    return 0;
}
