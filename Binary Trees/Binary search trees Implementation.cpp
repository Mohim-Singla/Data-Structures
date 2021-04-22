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

    search_node(root,3);
    search_node(root,4);
    search_node(root,5);
    search_node(root,25);
    search_node(root,17);
    search_node(root,32);

    return 0;
}
