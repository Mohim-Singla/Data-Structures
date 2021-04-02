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

node* search_key(node* root, int key, node*& pre, node*& suc)
{
    if (root==NULL)
    {
        return root;
    }
    if (root->data>key)
    {
        suc=root;
        root=search_key(root->lchild, key,pre,suc);
    }
    if (root->data<key)
    {
        pre=root;
        root=search_key(root->rchild, key,pre,suc);
    }
    else return root;

}

void pre_succ(node* root, int key,node*& pre, node*& suc)
{
    if (root==NULL)
    {
        return;
    }

    root=search_key(root, key, pre, suc);
    if (root==NULL)
    {
        cout<<"Key="<<key<<" ->key not found";
        exit(0);
    }
    if (root->data==key)
    {
        if (root->lchild!=NULL)
        {
            pre=root->lchild;
            while(pre->rchild)
            {
                pre=pre->rchild;
            }

        }
        if (root->rchild!=NULL)
        {
            suc=root->rchild;
            while(suc->lchild)
            {
                suc=suc->lchild;
            }

        }
    }

    return;
}

int main()
{
    node* root=NULL;
    root=create(root, 16);
    root=create(root, 4);
    root=create(root, 10);
    root=create(root, 12);
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

    node* suc=NULL;
    node* pre=NULL;
    pre_succ(root, 6,pre,suc);

    cout<<"key=6: predecessor: "<<pre->data<<endl;
    cout<<"key=6: Successor: "<<suc->data<<endl;
    pre_succ(root, 77,pre,suc);
    cout<<"key=77: predecessor: "<<pre->data<<endl;
    cout<<"key=77: Successor: "<<suc->data<<endl;
    return 0;
}
