#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number=" << endl;

    cin >> n;

    int arr[n];
    cout << "Enter the numbers=" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
    cout << "Sorted  numbers=" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}