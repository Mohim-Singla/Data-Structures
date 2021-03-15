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

void search_node(node* root,int data)
{
    if(root==NULL)
    {
        cout<<"Not present"<<endl;
        return;
    }
    else if(root->data<data)
    {
        return search_node(root->rchild,data);
    }
    else if(root->data>data)
    {
        return search_node(root->lchild,data);
    }
    else
    {
        cout<<"Element present"<<endl;
        return;
    }
}

void minimum(node* root)
{
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
    cout<<root->data<<endl;
}

void maximum(node* root)
{
    while(root->rchild!=NULL)
    {
        root=root->rchild;
    }
    cout<<root->data<<endl;
}

int main()
{
    node* root=NULL;
    root=create(root, 16);
    root=create(root, 4);
    root=create(root, 10);
    root=create(root, 20);
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

    minimum(root);
    maximum(root);
    return 0;
}
