#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head,*next;
    head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    next=(struct node *)malloc(sizeof(struct node));
    next->data=2;
    next->link=NULL;
    head->link=next;

    next=(struct node *)malloc(sizeof(struct node));
    next->data=3;
    next->link=NULL;
    head->link->link=next;

    cout<<"Linked list created is: ";
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr ->link;
    }

}
