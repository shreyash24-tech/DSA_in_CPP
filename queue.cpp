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

class queue
{
public:
    Node *head;
    Node *tail;

    queue()
    {
        head = tail = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is all ready Empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void front()
    {
        cout << "Element at Front =" << head->data << endl;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.display();

    q1.pop();
    q1.pop();
    q1.display();

    q1.front();
}