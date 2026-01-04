#include <iostream>
using namespace std;
#define size 10

int Hashtable[size];

void insert(int key)
{
    int index = key % size;
    int i = 0;

    while (Hashtable[(index + i * i) % size] != -1)
    {
        i++;
    }
    Hashtable[(index + i * i) % size] = key;
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        cout << i << "        -->         " << Hashtable[i] << endl;
    }
}

int main()
{
    for (int i = 0; i < size; i++)
    {
        Hashtable[i] = -1;
    }
    int key, n;

    cout << "Enter the number of elements =" << endl;
    cin >> n;

    cout << " Enter the keys=" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        insert(key);
    }

    display();
    return 0;
}