#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
};
node *head=NULL;
void insertin(int x)
{
    node *temp=(struct node *)malloc(sizeof(struct node));
    node *temp2; //to store last node so as to prevent traversal every time this function is called.
    temp->data=x;
    temp->next=NULL;
    if (head==NULL)
    {
        head=temp;
        temp2=head;
    }
    else
    {
        temp2->next=temp;
        temp2=temp;
    }
}
struct node* reversing(struct node *head)
{
    node *temp=NULL;
    node *temp1=NULL;

    while(head!=NULL)
    {
        temp=head->next;
        head->next=temp1;
        temp1=head;
        head=temp;
    }
    head=temp1;
    return head;
}

void display()
{
    node *disp=head;

    if(disp==NULL)
    {
        cout<<"Linked List is Empty.";
        return;
    }
    else
    {
        while (disp!=NULL)
        {
            cout<<disp->data<<" ";
            disp=disp->next;
        }
        cout<<endl;
    }
}

int main()
{
    insertin(1);
    insertin(2);
    insertin(3);
    insertin(4);
    insertin(5);
    insertin(6);
    insertin(7);
    insertin(8);
    display();
    head=reversing(head);
    display();

    return 0;
}

