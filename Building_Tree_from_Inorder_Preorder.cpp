#include <iostream>

using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* build(int preorder[], int inorder[], int start, int end1)
{
    static int i = 0;
    if (start>end1)
    {
        return NULL;
    }
    int data1=preorder[i];
    i++;
    node* temp=new node;
    temp->data=data1;
    temp->lchild=temp->rchild=NULL;

    if (start==end1)
    {
        return temp;
    }
    int position;
    for (int j=start;j<=end1;j++)
    {
        if (inorder[j]==data1)
        {
            position=j;
            break;
        }
    }
    temp->lchild=build(preorder, inorder, start, position-1);
    temp->rchild=build(preorder, inorder, position+1, end1);

    return temp;
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
    int inorder[]={2,4,6,7,8,10,11,12,14,16,20,21,25,31,32};
    int preorder[]={16,4,2,10,8,6,7,12,11,14,20,25,21,31,32};
    node* root = build(preorder, inorder, 0, 14);
    inorder_traversal(root);
    return 0;
}
