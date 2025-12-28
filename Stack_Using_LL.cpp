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

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << " Stack UnderFlow" << endl;
        }
        Node *temp = top;
        cout << "Poped=" << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void display()
    {
        Node *temp = top;
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
    Stack s;
    s.push(10);
    s.push(20);
    s.display();
    s.pop();
    s.display();
    return 0;
}