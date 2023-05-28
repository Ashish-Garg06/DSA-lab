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

    // Insert a new node at the beginning of the list
    void insert_at_beginning(int value)
    {
        Node *Newnode = new Node(value);
        Newnode->front = Head;
        Newnode->back = nullptr;
        Head = Newnode;
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

    void insertAtPosition(int data, int position)
    {
        if (position <= 0)
        {
            insert_at_beginning(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = Head;
        Node *previous = nullptr;
        int count = 1;

        while (current != nullptr && count < position)
        {
            previous = current;
            current = current->front;
            count++;
        }

        newNode->front = current;
        current->back = newNode;
        if (previous != nullptr)
        {
            previous->front = newNode;
            newNode->back = previous;
        }
        else
        {
            Head = newNode;
        }
    }

    void deleteAtBeginning()
    {
        if (Head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = Head;
        Head = Head->front;
        delete temp;
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

    void deleteAtEnd()
    {
        if (Head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *current = Head;
        Node *previous = nullptr;

        while (current->front != nullptr)
        {
            previous = current;
            current = current->front;
        }

        if (previous != nullptr)
        {
            previous->front = nullptr;
        }
        else
        {
            Head = nullptr;
        }

        delete current;
    }

    // Delete node at a specific position in the list
    void deleteAtPosition(int position)
    {
        if (Head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (position <= 0)
        {
            deleteAtBeginning();
            return;
        }

        Node *current = Head;
        Node *previous = nullptr;
        int count = 1;

        while (current != nullptr && count < position)
        {
            previous = current;
            current = current->front;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Invalid position. Node not found." << endl;
            return;
        }

        if (previous != nullptr)
        {
            previous->front = current->front;
            current->back=previous;
        }
        else
        {
            Head = current->front;
        }

        delete current;
    }

    int countNodes()
    {
        Node *current = Head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->front;
        }
        return count;
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

    myList.insert_at_beginning(3);
    myList.insert_at_beginning(2);
    myList.insert_at_beginning(1);

    myList.insert_at_end(4);
    myList.insert_at_end(5);

    myList.insertAtPosition(10, 2);

    cout << "Linked List after insertions: ";
    myList.displayfrombeginning();

    myList.deleteAtPosition(2);
    myList.displayfrombeginning();


    cout << "Linked List after deletions: ";
    myList.displayfrombeginning();

    int nodeCount = myList.countNodes();
    cout << "Number of nodes in the list: " << nodeCount << endl;


    return 0;
}