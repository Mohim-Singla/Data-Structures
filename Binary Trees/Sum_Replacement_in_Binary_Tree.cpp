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

void sum_replacement(node* root)
{
    if (root==NULL)
    {
        return ;
    }
    sum_replacement(root->lchild);
    sum_replacement(root->rchild);

    if (root->lchild!=NULL)
    {
        root->data+=root->lchild->data;
    }
    if (root->rchild!=NULL)
    {
        root->data+=root->rchild->data;
    }
}

void inorder_traversal(node* root)
{
    if (root==NULL)
    {
        return;
    }
    inorder_traversal(root->lchild);
    cout<<root->data<<" ";
    inorder_traversal(root->rchild);
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

    sum_replacement(root);
    inorder_traversal(root);
    return 0;
}

