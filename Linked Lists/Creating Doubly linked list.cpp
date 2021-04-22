#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};
node *head=NULL;
void insertemp(int x)
{
    struct node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    head=temp;
}
void insertprev(int x)
{
    struct node *temp=new node;
    if (head==NULL)
    {
        insertemp(x);
    }
    else
    {
        temp->data=x;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertend(int x)
{
    node *temp=new node;
    node *temp2=new node;
    temp2=head;
    if (head==NULL)
    {
        insertemp(x);
    }
    else
    {
        temp->data=x;
        temp->next=NULL;
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp->prev=temp2;
        temp2->next=temp;
    }
}
void insertafter(int x, int position)
{
    node *temp=new node;
    node *temp2=new node;
    node *add=new node;
    add->data=x;
    temp2=head;
    if (position==0)
    {
        insertprev(x);
    }
    else
    {
        while (position!=1)
    {
        temp2=temp2->next;
        position--;
    }
    temp=temp2->next;
    add->next=temp;
    temp->prev=add;
    add->prev=temp2;
    temp2->next=add;
    }
}
void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{

    insertemp(2);
    insertprev(1);
    insertend(3);
    insertend(4);
    insertprev(0);
    insertafter(9, 2); //data, position after
    display();
}
