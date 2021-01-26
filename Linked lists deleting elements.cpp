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
struct node* del_first(struct node *head)
{
    node *current=head;
    head=head->next;
    free(current);
    current=NULL;
    return head;
}
void del_between(int x)
{
    node *current=head;
    node *temp=new node;
    temp=head;

    if (head==NULL)
    {
        cout<<"List is already empty."<<endl;
        return;
    }
    if (x==1)
    {
        head=del_first(head);
    }
    else
    {
        while(x!=1)
        {
            temp=current;
            current=current->next;
            x--;
        }
        temp->next=current->next;
        free(current);
        current=NULL;
    }

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
    head=del_first(head);
    display();
    del_between(3);
    display();
    del_between(5);
    display();
    del_between(2);
    display();
    del_between(1);
    display();
    return 0;
}
