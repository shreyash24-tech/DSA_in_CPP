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

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void push_middle(int val, int pos)
    {
        Node *newNode = new Node(val);

        if (pos < 0)
        {
            cout << "Position is Wrong" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print_LL()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next = NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

void pop_middle(int pos)
{

Node *temp=head;
Node *pre;
if(pos<0)
{
cout<<"Wrong position"<<endl;

}
if(pos==0)
{
pop_front();
}
for(int i=0;i<pos-1;i++)
{
pre=temp;
temp=temp->next;

}

pre->next=temp->next;
temp->next=NULL;
delete temp;

}

};


int main()
{
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    l.push_back(4);
    l.push_middle(3, 2);
    l.print_LL();


    l.pop_front();
    l.pop_back();
    l.pop_middle(2);
    l.print_LL();
}