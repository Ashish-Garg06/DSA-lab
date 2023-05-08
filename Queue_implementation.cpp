#include <iostream>
using namespace std;

const int S = 5;

class Queue
{
private:
    int arr[S];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void dequeue()
    {
        // Check if the queue is empty
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow: deletion not allowed\n";
        }
        else
        {
            // Increment the front index to remove the element
            front++;
            // If the front index has crossed the rear index,
            // reset both front and rear to -1 to indicate an empty queue
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }

    void enqueue(int y)
    {
        // Check if the queue is full
        if (rear == S - 1)
        {
            cout << "Queue overflow: addition not allowed\n";
        }
        else
        {
            // Increment the rear index and add the element to the queue
            rear++;
            arr[rear] = y;
            cout << "Element " << y << " was added to the queue." << endl;
            // If the front index is still -1, update it to 0
            if (front == -1)
            {
                front = 0;
            }
        }
    }

    void display()
    {
        // Check if the queue is empty
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            // Print the elements in the queue
            cout << "Elements in the queue: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a new instance of the Queue class
    Queue q;
    // Test dequeue operation on an empty queue
    q.dequeue();
    // Add elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // Test adding an element to a full queue
    q.enqueue(6);
    // Display the elements in the queue
    q.display();
    // Remove two elements from the queue
    q.dequeue();
    q.dequeue();
    // Display the elements in the queue again
    q.display();
    return 0;
}
