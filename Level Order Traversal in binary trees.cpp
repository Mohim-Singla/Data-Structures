#include <iostream>
#include <stdlib.h>
#include <queue>

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

void level_traversal(node* root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        queue <node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* temp=q.front();
            if(temp->lchild!=NULL)
            {
                q.push(temp->lchild);
            }
            if (temp->rchild!=NULL)
            {
                q.push(temp->rchild);
            }
            cout<<q.front()->data<<" ";
            q.pop();

        }
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

    level_traversal(root);
    return 0;
}
