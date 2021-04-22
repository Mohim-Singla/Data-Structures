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

void sum(node* root, int n)
{
    if (root==NULL)
    {
        cout<<"-1";
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum1=0;
    while(!q.empty())
    {
        node* val=q.front();
        q.pop();
        //q.push(NULL);
        if (val!=NULL)
        {
            if (level==n)
            {
                sum1+=val->data;

            }
            if (val->lchild)
            {
                q.push(val->lchild);
            }
            if (val->rchild)
            {
                q.push(val->rchild);
            }
        }


        else if(!q.empty())
            {
                q.push(NULL);
                level++;
            }


    }
    cout<<sum1<<endl;;
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

    cout<<"Sum at level 3: ";
    sum(root, 3);
    cout<<"Sum at level 4: ";
    (sum(root,4));
    return 0;
}
