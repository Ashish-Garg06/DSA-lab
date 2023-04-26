#include <iostream>
using namespace std;

const int S = 5;

class Queue {
private:
    int arr[S];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Queue Underflow: deletion not allowed\n";
        } else {
            front++;
            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    void enqueue(int y) {
        if (rear == S - 1) {
            cout << "Queue overflow: addition not allowed\n";
        } else {
            rear++;
            arr[rear] = y;
            cout<<"Element "<<y << " was added to the queue."<<endl;
            if (front == -1) {
                front = 0;
            }
        }
    }

    void display() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Elements in the queue: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
