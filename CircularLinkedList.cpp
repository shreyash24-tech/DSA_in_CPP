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

class CircularList
{
public:
    Node *head;
    Node *tail;
    CircularList()
    {
        head = tail = NULL;
    }

    void insert_beg(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
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
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void print()
    {
        Node *temp;

        temp = head;

        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        do
        {
            cout << temp->data << "->";
            temp = temp->next;

        } while (temp != head);

        cout << temp->data<<endl;
    }

    void delete_beg()
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
            Node *temp = head;
            head = head->next;
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
            Node *prev = head;

            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void insert_middle(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "INVALID POSITION " << endl;
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
        }
    }

    void delete_middle(int pos)
    {
        if (pos < 0)
        {

            cout << "INVALID POSITION" << endl;
        }

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
                p = head;
                temp = temp->next;
            }

            p->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main()
{
    CircularList c;
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
        cout << "7 Print Circular Linked List"<<endl;

        cout << "8 EXIT" << endl;

        cout << "Enter your choice" << endl;
        cin >> ch;

        switch (ch)
        {

        case 1:
            int val1;
            cout << "Enter the value" << endl;
            cin >> val1;
            c.insert_beg(val1);
            break;

        case 2:
            int val2;
            cout << "Enter the value" << endl;
            cin >> val2;
            c.insert_end(val2);
            break;

        case 3:
            int val3;
            int pos1;

            cout << "Enter the value" << endl;
            cin >> val3;
            cout << "Enter the position" << endl;
            cin >> pos1;

            c.insert_middle(val3, pos1);
            break;

        case 4:

            c.delete_beg();
            break;

        case 5:

            c.delete_end();
            break;

        case 6:
            int pos2;

            cout << "Enter the position" << endl;
            cin >> pos2;

            c.delete_middle(pos2);
            break;

        case 7:
            c.print();
            break;

        case 8:
            return 0;
            break;
        }

    } while (ch != 8);

    // c.insert_beg(2);
    // c.insert_beg(1);
    // c.insert_end(3);
    // c.insert_middle(1, 1);
    // c.delete_middle(1);

    // // c.delete_beg();
    // // c.delete_end();
    // c.print();
}