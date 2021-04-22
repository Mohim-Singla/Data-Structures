#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
};
node *head=NULL;
node *tail=NULL;
void insertemp(int x)
{
    node *temp =new node;
    temp->data=x;
    head=temp;
    tail=temp;
    head->next=head;
}
void insertbeg(int x)
{
    if (head==NULL)
    {
        insertemp(x);
    }
    else
    {
        node *temp=new node;
        temp->data=x;
        temp->next=head;
        tail->next=temp;
        head=temp;
    }
}
void insertend(int x)
{
    if (head==NULL)
    {
        insertemp(x);
    }
    else
    {
        node *temp=new node;
        temp->data=x;
        tail->next=temp;
        temp->next=head;
        tail=temp;
    }
}
void insertafter(int x, int position)
{
    node *temp=new node;
    node *temp2=new node;
    temp=head;
    int count=0;
    do
    {
        temp=temp->next;
        count++;
    }while(temp!=tail->next);
    if (position>count)
    {
        cout<<"Position cannot be greater than "<<count<<endl;
    }
    else if (position==count)
    {
        insertend(x);
    }
    else
    {

        while(position!=1)
        {
            head=head->next;
            position--;
        }
        temp2->data=x;
        temp2->next=head->next;
        head->next=temp2;
        head=tail->next;
    }
}
void delfirst()
{
    head=head->next;
    free(tail->next);
    tail->next=head;
}
void dellast()
{
    node *temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(tail);
    tail=temp;
}
void delafter(int position)
{
    node *temp=head;
    while(position!=1)
    {
        head=head->next;
        position--;
    }
    temp=head->next;
    head->next=temp->next;
    free(temp);
    head=tail->next;

}

void display()
{
    node *temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=tail->next);
    cout<<endl;
}
int main()
{
    insertend(1);
    insertbeg(2);
    insertbeg(3);
    insertbeg(4);
    insertbeg(10);
    insertend(5);
    display();
    insertafter(9, 3);
    display();
    delfirst();
    display();
    dellast();
    display();
    delafter(2);
    display();
}
