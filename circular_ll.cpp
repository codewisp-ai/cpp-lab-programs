#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class circularList
{
public:
    Node *head;
    Node *tail;
    circularList()
    {
        head = tail = NULL;
    }

    void insert_head(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
            return;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;

            // newnode->next=tail->next;
            // tail->next=newnode;  this is same as below
        }
    }

    void insert_tail(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void delete_head()
    {

        if (head == NULL)
        {
            cout << "UNDERFLOW CONDITION " << endl;
        }
        else if (tail == head)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void delete_tail()
    {
        if (head == NULL)
        {
            cout << "UNDERFLOW CONDITION " << endl;
        }
        else if (tail == head)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node *temp = tail;
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            temp->next = NULL;
            tail->next = head;
            delete temp;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "CIRCULAR LIST IS EMPTY" << endl;
        }
        cout << head->data << " -> ";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // tail pointer is needed
    // head=tail->next

    circularList cl;
    cl.insert_head(1);
    cl.display();
    cl.insert_head(2);
    cl.display();
    cl.insert_head(3);
    cl.display();
    cl.insert_tail(4);
    cl.display();
    cl.insert_tail(5);
    cl.display();
    cl.insert_tail(6);
    cl.display();
    cl.delete_head();
    cl.display();
    cl.delete_head();
    cl.display();
    cl.delete_tail();
    cl.display();
    cl.delete_tail();
    cl.display();

    return 0;
}