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

int height(node* root)
{
    if (root==NULL)
    {
        return -1;
    }
    return max(height(root->lchild), height(root->rchild)) + 1;
}

bool check(node* root)
{
    if (root==NULL)
    {
        return true;
    }

    int h1=height(root->lchild);
    int h2=height(root->rchild);

    if (abs(h1-h2)<=1 && check(root->lchild) && check(root->rchild))
    {
        return true;
    }
    return 0;

}

int main()
{
    node* root=NULL;
    root=create(root, 16);
    root=create(root, 4);
    root=create(root, 17);


    bool a=check(root);
    if (a)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
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
    a=check(root);
    if (a)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}

