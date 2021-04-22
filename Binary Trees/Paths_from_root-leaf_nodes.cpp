#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
int data;
node* lchild;
node* rchild;
};

node* create_node(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

node* create(node* root, int data)
{
    if(root==NULL)
    {
        root = create_node(data);
        return root;
    }
    else
    {
        if (data<root->data)
        {
            root->lchild = create(root->lchild,data);
        }
        else
        {
            root->rchild=create(root->rchild, data);
        }
        return root;
    }
}


void print_path(node* root, int arr[], int loc)
{
    if (root==NULL)
    {
        return;
    }
    arr[loc]=root->data;
    loc++;
    if (root->lchild==NULL && root->rchild==NULL)
    {
        for (int i=0;i<loc;i++)
        {
            cout<<arr[i]<<" ";

        }
        cout<<endl;
    }

    print_path(root->lchild, arr, loc);
    print_path(root->rchild, arr, loc);
}

int main()
{
    node* root=NULL;
    root=create(root, 16);
    root=create(root, 4);
    root=create(root, 10);
    root=create(root, 20);
    root=create(root, 12);
    root=create(root, 11);
    root=create(root, 25);
    root=create(root, 8);
    root=create(root, 6);
    root=create(root, 14);
    root=create(root, 2);
    root=create(root, 21);
    root=create(root, 31);
    root=create(root, 7);
    root=create(root, 32);


    int arr[100];
    print_path(root, arr, 0);

}
