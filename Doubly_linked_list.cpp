#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class Doubly_LL
{
public:
    Node *head, *tail;

    Doubly_LL()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == 0)
        {
            head = tail = newNode;
            return;
        }

        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print_LL()
    {
        Node *temp;

        temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }

    void push_back(int val)
    {

        Node *newNode = new Node(val);

        if (head == 0)
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_middle(int val, int pos)
    {
        Node *temp;
        temp = head;
        Node *newNode = new Node(val);

        if (pos < 0)
        {
            cout << "WRONG POSITION" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void pop_front()
    {

        Node *temp = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        Node *temp = tail;

        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void pop_middle(int pos)
    {
        if (pos == 0)
        {
            pop_front();
            return;
        }

        if (pos < 0)
        {
            cout << "WRONG POSITION" << endl;
        }

        Node *temp, *p;
        temp = head;

        for (int i = 0; i < pos; i++)
        {
            p = temp;
            temp = temp->next;
        }

        p->next = temp->next;
        temp->next->prev = p;
        temp->next = NULL;

        delete temp;
    }
};

int main()
{
    Doubly_LL dll;
    // dll.push_front(3);
    // dll.push_front(2);
    // dll.push_front(1);
    // dll.push_back(4);
    // dll.push_middle(2, 1);
    // // dll.pop_front();
    // // dll.pop_back();
    // dll.pop_middle(2);
    // dll.print_LL();

    int choice;

    do
    {

        cout << "------MENU----------" << endl;
        cout << "1. Insert at First Position" << endl;

        cout << "2. Insert at Last Position" << endl;

        cout << "3. Insert at Middle Position" << endl;

        cout << "4. Delete at First Position" << endl;

        cout << "5. Delete at Last Position" << endl;

        cout << "6. Delete at Middle Position" << endl;

        cout << "7. Print Doubly Linked List" << endl;

        cout << "8.Exit" << endl;

        cout << "Enter your choice=" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            int val;
            cout << "Enter the value=" << endl;
            cin >> val;
            dll.push_front(val);
            break;

        case 2:
            int val2;
            cout << "Enter the value=" << endl;
            cin >> val2;
            dll.push_back(val2);
            break;

        case 3:
            int val3, pos;
            cout << "Enter the value=" << endl;
            cin >> val3;
            cout << "Enter the position=" << endl;
            cin >> pos;
            dll.push_middle(val3, pos);
            break;

        case 4:
            dll.pop_front();

            break;

        case 5:
            dll.pop_back();

            break;

        case 6:
            int pos1;
            cout << "Enter the position" << endl;
            cin >> pos;

            dll.pop_middle(pos1);

            break;

        case 7:
            dll.print_LL();
            break;

        case 8:
            return 0;
            break;
        default:
            cout << "WRONG CHOICE" << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}