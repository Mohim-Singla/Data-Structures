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

int find_height(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lheight=find_height(root->lchild);
    int rheight=find_height(root->rchild);

    return(max(lheight, rheight)+1);

}

int find_diameter(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lheight=find_height(root->lchild);
    int rheight=find_height(root->rchild);
    int diam=lheight+rheight+1;

    int ldiam=find_diameter(root->lchild);
    int rdiam=find_diameter(root->rchild);

    return(max(max(ldiam,rdiam),diam));
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

    int h=find_diameter(root);
    cout<<h;
    return 0;
}
