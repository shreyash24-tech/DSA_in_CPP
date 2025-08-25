#include <iostream>
using namespace std;

class Customer
{
public:
    int id;
    char name[50];
};

Customer customer[100];
int cus_count = 0;

void addCustomer()
{
    cout << "Enter the Id of Customer=" << endl;
    cin >> customer[cus_count].id;
    cout << "Enter the name of customer" << endl;
    cin >> customer[cus_count].name;
    cus_count++;
    cout << "Customer Added Successfully";
}

void display()
{
    if (cus_count == 0)
    {
        cout << "No Customer found" << endl;
        return;
    }
    cout << "---------------CUSTOMER LIST-------------------" << endl;

    for (int i = 0; i < cus_count; i++)
    {
        cout << "Id=" << customer[i].id << endl;
        cout << "Name=" << customer[i].name << endl;
    }
}

void update()
{
    int id;
    cout << "Enter the ID to Update the Name=" << endl;
    cin >> id;

    for (int i = 0; i < cus_count; i++)
    {
        if (customer[i].id == id)
        {
            cout << "Enter the new Name=";
            cin >> customer[i].name;

            cout << "Updated record Successfully" << endl;
            cout << "UPDATED RECORD";
            display();
        }
    }
}

void delete_cus()
{
    int id;
    cout << "Enter the id of customer=" << endl;
    cin >> id;

    for (int i = 0; i < cus_count; i++)
    {
        if (customer[i].id == id)
        {
            for (int j = i; j < cus_count - 1; j++)
            {
                customer[j] = customer[j + 1];
            }
        }
    }
    cout << "Deleted Customer successfully" << endl;
    display();
}

int main()
{
    int choice = 0;

    do
    {

        cout << "------------MENU------------" << endl;
        cout << "1 -ADD NEW CUSTOMER" << endl;
        cout << "2 -DISPLAY CUSTOMER RECORD" << endl;
        cout << "3 -UPDATE CUSTOMER REACORD" << endl;
        cout << "4 -DELETE CUSTOMER RECORD" << endl;

        cout << "Enter the choice" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            addCustomer();
            break;

        case 2:
            display();
            break;

        case 3:
            update();
            break;

        case 4:
            delete_cus();
            break;

        default:
            cout << "WRONG CHOICE" << endl;
            break;
        }

    } while (choice != 5);
}