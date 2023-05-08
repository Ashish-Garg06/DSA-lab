#include <iostream>
using namespace std;

const int MAX = 10; // Maximum size of the queue

class CircularQueue
{
private:
    char queue[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == MAX - 1) || (rear == front - 1);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void insert(char value)
    {
        if (isFull())
        {
            cout << "Error: Queue is full (Overflow)" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = value;
        cout << "Element '" << value << "' inserted into the queue" << endl;
    }

    char remove()
    {
        if (isEmpty())
        {
            cout << "Error: Queue is empty (Underflow)" << endl;
            return '\0';
        }

        char value = queue[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        cout << "Element '" << value << "' removed from the queue" << endl;
        return value;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue contents: ";
        int i;

        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (i = front; i < MAX; i++)
            {
                cout << queue[i] << " ";
            }

            for (i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue queue;
    char choice, value;

    do
    {
        cout << "Circular Queue Operations:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter element to insert: ";
            cin >> value;
            queue.insert(value);
            break;
        case '2':
            queue.remove();
            break;
        case '3':
            queue.display();
            break;
        case '4':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Error: Invalid choice" << endl;
            break;
        }

        cout << endl;
    } while (choice != '4');

    return 0;
}