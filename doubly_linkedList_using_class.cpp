#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *front;
    Node *back;

    Node(int value)
    {
        data = value;
        front = nullptr;
        back = nullptr;
    }
};

class Doubly_linked_list
{
private:
    Node *Head;
    Node *Tail;

public:
    Doubly_linked_list()
    {
        Head = nullptr;
        Tail = nullptr;
    }

    // Insert a new node at the end of the list
    void insert_at_end(int value)
    {
        Node *Newnode = new Node(value);
        if (Head == nullptr)
        {
            // If the list is empty, set the new node as both the head and tail
            Head = Newnode;
            Tail = Newnode;
        }
        else
        {
            Node *current = Head;
            while (current->front != nullptr)
            {
                // Traverse the list to find the last node
                current = current->front;
            }
            current->front = Newnode;
            Newnode->back = current;
            Tail = Newnode; // Update the tail to the newly inserted node
        }
    }

    // Display the list from the beginning (head to tail)
    void displayfrombeginning()
    {
        Node *current = Head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->front;
        }
        cout << endl;
    }

    // Display the list from the end (tail to head)
    void displayfromend()
    {
        Node *current = Tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->back;
        }
        cout << endl;
    }
};

int main()
{
    Doubly_linked_list myList;

    for (int i = 1; i <= 100; i++)
    {
        myList.insert_at_end(i);
    }

    myList.displayfrombeginning();

    cout << "\n \n";

    myList.displayfromend();

    return 0;
}