#include <iostream>
using namespace std;

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

class Single_Linked_list
{
private:
    Node *Head;

public:
    Single_Linked_list()
    {
        Head = nullptr;
    }

    void insert_at_end(int value)
    {
        Node *Newnode = new Node(value);
        if (Head == nullptr)
        {
            Head = Newnode;
        }
        else
        {
            Node *current = Head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = Newnode;
        }
    }

    void Traverse_linked_list()
    {
        cout << "\n";
        Node *current = Head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};
int main()
{
    Single_Linked_list mylist;

    for (int i = 1; i <= 100; i++)
    {
        mylist.insert_at_end(i);
    }

    mylist.Traverse_linked_list();
    return 0;
}
