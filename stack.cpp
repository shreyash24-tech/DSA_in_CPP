#include <iostream>
using namespace std;

#define size 5

class stack
{
public:
    int top;
    int arr[size];

    stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == size - 1)
            cout << "Stack is Overflow Cant push" << value << endl;

        else
        {
            top++;
            arr[top] = value;
            cout << value << " is Inserted into the stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow , cant pop element" << endl;
        }

        else
        {
            cout << arr[top] << " pop from stack" << endl;
            top--;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
       }

        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

void peek()
{
if(top==-1)
{
cout<<"Stack is Empty"<<endl;

}
else
{
cout<<arr[top]<<" is top most element in the Stack"<<endl;
}
}
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(15);
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.peek();
}