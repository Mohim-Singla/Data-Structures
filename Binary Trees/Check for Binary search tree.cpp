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

bool check(node* root, int minv, int maxv)
{
    if(root==NULL)
    {
        return true;
    }
    else if (root->data>minv && root->data<maxv && check(root->lchild, minv, root->data) && check(root->rchild, root->data, maxv))
    {
        return true;
    }
    else
    {
        return false;
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
    root=create(root, 6);
    root=create(root, 14);
    root=create(root, 2);
    root=create(root, 21);
    root=create(root, 31);
    root=create(root, 7);
    root=create(root, 32);

    bool ans=check(root,INT_MIN,INT_MAX);
    if(ans)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}
