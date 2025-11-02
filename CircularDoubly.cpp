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

class CircularDoubly
{
public:
    Node *head;
    Node *tail;

    CircularDoubly()
    {
        head = tail = NULL;
    }

    void insert_beg(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
        }

        else
        {

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            tail->next = head;
        }
    }

    void insert_end(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
        }

        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        do
        {
            cout << temp->data << "-->";
            temp = temp->next;

        } while (temp != head);

        cout << temp->data << endl;
    }

    void delete_beg()
    {
        if (head == NULL)
            return;

        else if (head == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void delete_end()
    {
        if (head == NULL)
            return;

        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }

        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;

            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void insert_mid(int val, int pos)
    {

        if (pos < 0)
        {
            cout << "INVALID position" << endl;
            return;
        }

        else if (pos == 0)
        {
            insert_beg(val);
        }

        else
        {
            Node *newNode = new Node(val);
            Node *temp = head;

            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            temp->next->prev = newNode;
        }
    }

    void delete_middle(int pos)
    {
        if (pos < 0)
            return;

        else if (pos == 0)
        {
            delete_beg();
        }

        else
        {
            Node *temp = head;
            Node *p;

            for (int i = 0; i < pos; i++)
            {
                p = temp;
                temp = temp->next;
            }

            p->next = temp->next;
            temp->next->prev = p;

            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }
};

int main()
{
    CircularDoubly cd;
    int ch;
    do
    {
        cout << "------------MENU-----------" << endl;
        cout << "1 Insert first" << endl;
        cout << "2 Insert End" << endl;
        cout << "3 Insert Middle" << endl;
        cout << "4 Delete first" << endl;
        cout << "5 Delete End" << endl;
        cout << "6 Delete Middle" << endl;
        cout << "7 Print CirculaLinked List" << endl;

        cout << "8 EXIT" << endl;

        cout << "Enter your choice" << endl;
        cin >> ch;

        switch (ch)
        {

        case 1:
            int val1;
            cout << "Enter the value" << endl;
            cin >> val1;
            cd.insert_beg(val1);
            break;

        case 2:
            int val2;
            cout << "Enter the value" << endl;
            cin >> val2;
            cd.insert_end(val2);
            break;

        case 3:
            int val3;
            int pos1;

            cout << "Enter the value" << endl;
            cin >> val3;
            cout << "Enter the position" << endl;
            cin >> pos1;

            cd.insert_mid(val3, pos1);
            break;

        case 4:

            cd.delete_beg();
            break;

        case 5:

            cd.delete_end();
            break;

        case 6:
            int pos2;

            cout << "Enter the position" << endl;
            cin >> pos2;

            cd.delete_middle(pos2);
            break;

        case 7:
            cd.print();
            break;

        case 8:
            return 0;
            break;
        }

    } while (ch != 8);

    return 0;
}