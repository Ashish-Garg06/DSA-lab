#include <iostream>

using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert node at the beginning of the list
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert node at the end of the list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert node at a specific position in the list
    void insertAtPosition(int data, int position)
    {
        if (position <= 0)
        {
            insertAtBeginning(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = head;
        Node *previous = nullptr;
        int count = 0;

        while (current != nullptr && count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        newNode->next = current;
        if (previous != nullptr)
        {
            previous->next = newNode;
        }
        else
        {
            head = newNode;
        }
    }

    // Delete node at the beginning of the list
    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete node at the end of the list
    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }

        if (previous != nullptr)
        {
            previous->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

        delete current;
    }

    // Delete node at a specific position in the list
    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (position <= 0)
        {
            deleteAtBeginning();
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        int count = 0;

        while (current != nullptr && count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Invalid position. Node not found." << endl;
            return;
        }

        if (previous != nullptr)
        {
            previous->next = current->next;
        }
        else
        {
            head = current->next;
        }

        delete current;
    }

    // Traverse the list and print all nodes
    void traverse()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Count the number of nodes in the list
    int countNodes()
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Main function
int main()
{
    LinkedList myList;

    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);

    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    myList.insertAtPosition(10, 2);

    cout << "Linked List after insertions: ";
    myList.traverse();

    myList.deleteAtBeginning();
    myList.deleteAtEnd();

    myList.deleteAtPosition(2);

    cout << "Linked List after deletions: ";
    myList.traverse();

    int nodeCount = myList.countNodes();
    cout << "Number of nodes in the list: " << nodeCount << endl;

    return 0;
}