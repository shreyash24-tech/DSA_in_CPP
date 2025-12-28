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

class Queue
{
public:
    Node *Front;
    Node *Rear;
    Queue()
    {
        Front = Rear = NULL;
    }
    void addRear(int val)
    {
        Node *newNode = new Node(val);
        if (Rear == NULL)
        {
            Front = Rear = newNode;
            return;
        }
        Rear->next = newNode;
        Rear = newNode;
    }

    void deleteFront()
    {
        if (Front == NULL)
        {
            cout << "Queue is already EMPTY" << endl;
            return;
        }
        Node *temp = Front;
        Front = Front->next;
        temp->next = NULL;
        delete temp;
    }
    void display()
    {
        Node *temp = Front;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Queue q;
    q.addRear(10);
    q.addRear(20);
    q.addRear(30);
    q.display();
    q.deleteFront();
    q.display();
    return 0;
}