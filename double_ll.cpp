#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class doublyList
{
public:
    Node *head;
    Node *tail;
    doublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;

            head = newnode;
            return;
        }
    }

    void push_back(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            return;
        }
    }
    void pop_front()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "UNDERFLOW CONDITION OCCUR" << endl;
        }

        else if (head == tail)
        {
            head = tail = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        Node *temp = tail;
        if (head == NULL)
        {
            cout << "UNDERFLOW CONDITION OCCUR" << endl;
        }

        else if (head == tail)
        {
            head = tail = NULL;
            delete temp;
        }
        else{
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "DOUBLE LINKED LIST IS EMPTY" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    doublyList dll;
    dll.display();
    dll.push_front(3);
    dll.display();
    dll.push_back(2);
    dll.display();
    dll.push_front(1);
    dll.display();
    dll.pop_front();
    dll.display();
    dll.push_front(123);
    dll.display();
    dll.pop_back();
    dll.display();


    return 0;
}