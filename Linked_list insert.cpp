//adding nodes at different positions.
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
void ins_between(int x, int y)
{
    node *temp3=head;
    node *temp4=new node;

    temp4->data=x;
    temp4->next=NULL;
    int z=y;

    while(y!=1)
    {
        temp3=temp3->next;
        y--;
    }
    temp4->next=temp3->next;
    temp3->next=temp4;

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
    insertin(6);
    display();
    ins_between(5,2);
    display();
    ins_between(7,4);
    display();
    ins_between(8,3);
    display();
    ins_between(9,8);
    display();

    return 0;
}
