#include <iostream>
using namespace std;

class Node
{
public :

    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next=prev=NULL;

    }
};

class DLL
{
public:

Node *head;
Node * tail;
DLL()
{
head=tail=NULL;

}


void create()
{
int marks ,ch;
do{
cout<<"Enter the marks="<<endl;
cin>>marks;

push_back(marks);



cout<<"Do you want to Continue (Continue (1), Exit(0) )"<<endl;
cin>>ch;

}while(ch!=0);
}

void push_front(int val)
{
Node *newNode=new Node(val);

if(head==NULL)
{
head=tail=newNode;
return;

}
else
{
newNode->next=head;
head->prev=newNode;
head=newNode;

}
}

void push_back(int val)
{
Node *newNode= new Node(val);

if(head== NULL)
{
head =tail=newNode;
return;

}

else{
tail->next=newNode;
newNode->prev=tail;
tail=newNode;

}
}

void display()
{
Node *temp;
temp=head;

while(temp!=NULL)
{
cout<<temp->data<<"<-->";
temp=temp->next;

}
cout<<"NULL"<<endl;
}
};

int main()
{DLL dll ;
int ch;

do{
cout<<"MENU"<<endl;
cout<<"1 Create "<<endl;
cout<<"2 Display" <<endl;
cout<<"3 Exit"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;


cout<<"Enter the choice="<<endl;
cin>>ch;

switch(ch)
{

case 1:
dll.create();
break;

case 2:
dll.display();
break;

case 3:
return 0;
break;

default:
cout<<"Wrong choice"<<endl;
break;
}

}while(ch!=3);




return 0;

}

