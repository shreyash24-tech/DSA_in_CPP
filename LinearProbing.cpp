#include <iostream>
using namespace std;
#define size 10

int Hashtable[size];
void insert(int key)
{

    int index = key % size;

    while (Hashtable[index] != -1)
    {
        index = (index + 1) % size;
    }
    Hashtable[index] = key;
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        cout << i << "       -->         " << Hashtable[i] << endl;
    }
}

int main()
{

    for (int i = 0; i < size; i++)
    {
        Hashtable[i] = -1;
    }
    int n, key;
    cout << " Enter the number of elements =" << endl;
    cin >> n;
    cout << " Enter the Keys=" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        insert(key);
    }
    display();
    return 0;
}