#include <iostream>
using namespace std;

#define size 5

int main()
{
    int arr[size];
    cout << "Enter the 5 array elements (Sorted Elements Only): " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int low = 0, high = size - 1, mid;
    bool found = false;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
        cout << "Element not found in the array." << endl;

    return 0;
}
