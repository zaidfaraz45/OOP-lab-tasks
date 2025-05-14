#include <iostream>
#include <stdexcept>
using namespace std;

class QueueOverflowException : public exception
{
public:
    QueueOverflowException(int size, int front, int rear) {}
};

class QueueUnderflowException : public exception
{
public:
    QueueUnderflowException(int size, int front, int rear) {}
};

template <typename T>
class Queue
{
    int size;
    int front;
    int rear;
    T *data;

public:
    Queue(int s) : size(s), front(0), rear(0)
    {
        data = new T[size];
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(T value)
    {
        if ((front + 1) % size == rear)
        {
            throw QueueOverflowException(size, front, rear);
        }
        data[front] = value;
        front = (front + 1) % size;
    }

    T dequeue()
    {
        if (front == rear)
        {
            throw QueueUnderflowException(size, front, rear);
        }
        T val = data[rear];
        rear = (rear + 1) % size;
        return val;
    }
};

int main()
{
    Queue<int> q(3);

    try
    {
        cout << "Attempting to enqueue to a full queue...\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
    }
    catch (const QueueOverflowException &e)
    {
        cout << "Caught QueueOverflowException - ";
        cout << "what(): " << e.what() << endl;
    }

    try
    {
        cout << "\nAttempting to dequeue from an empty queue..." << endl;
        q.dequeue(); 
        q.dequeue(); 
        q.dequeue(); 
    }
    catch (const QueueUnderflowException &e)
    {
        cout << "Caught QueueUnderflowException - ";
        cout << "what(): " << e.what() << endl;
    }

    return 0;
}
