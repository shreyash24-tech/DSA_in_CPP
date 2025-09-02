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

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = tail = NULL;
    }

    void insert_first(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void print_ll()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_last(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_first()
    {

        Node *temp;
        temp = head;

        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void delete_last()
    {
        Node *temp;
        temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert_middle(int val, int pos)
    {

        if (pos == 0)
        {
            insert_first(val);
        }
        Node *newNode = new Node(val);
        Node *temp;
        temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_middle()
    {
        int pos;

        cout << "Enter the position=" << endl;
        cin >> pos;

        Node *temp;
        Node *pre;
        temp = head;

        for (int i = 0; i < pos; i++)
        {
            pre = temp;
            temp = temp->next;
        }

        pre->next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void sort()
    {
        bool swapped;
        Node *ptr1;
        Node *lPtr = NULL;
        do
        {

            ptr1 = head;
            swapped=false;
            while (ptr1->next != lPtr)
            {
                if (ptr1->data > ptr1->next->data)

                {
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped=true;
                }
                ptr1 = ptr1->next;
            }
            lPtr=ptr1;

        }while(swapped);
    }
};

int main()
{
    int ch;

    LinkedList ll;
    do
    {
        cout << "-------------MENU--------------" << endl;
        cout << "1 Insert data at first index" << endl;
        cout << "2 insert data at last index" << endl;
        cout << "3 insert data at middle" << endl;
        cout << "4 delete data from first index" << endl;
        cout << "5 delete data from last index" << endl;
        cout << "6 delete data from middle " << endl;
        cout << "7 print linked list" << endl;
        cout << "8 Sort the LinkList "<<endl;
        cout << "9 Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            int val;

            cout << "Enter value" << endl;
            cin >> val;
            ll.insert_first(val);
            break;

        case 2:
            int val2;

            cout << "Enter value" << endl;
            cin >> val2;
            ll.insert_last(val2);
            break;

        case 3:
            int val3;
            int pos;

            cout << "Enter value" << endl;
            cin >> val3;
            cout << "Enter the position" << endl;
            cin >> pos;
            ll.insert_middle(val3, pos);
            break;

        case 4:
            ll.delete_first();
            break;

        case 5:
            ll.delete_last();
            break;

        case 6:
            ll.delete_middle();
            break;

        case 7:
            ll.print_ll();
            break;

        case 8:
            cout<<"Original linked list=\n";
            ll.print_ll();
            ll.sort();
            cout<<"Swapped linked list=\n";
            ll.print_ll();
            break;

        case 9:
            return 0;
            break;
        default:
            cout << "Wrong choice" << endl;
            break;
        }

    } while (ch != 9);

    return 0;
}
