#include <iostream>

using namespace std;

void restoreup(int arr[], int pos);

void insert(int data, int arr[], int *pos)
{
    *pos+=1;
    arr[*pos]=data;
    restoreup(arr, *pos);
    return;
}

void restoreup(int arr[], int pos)
{
    while (arr[pos]>arr[pos/2])
    {
        int temp=arr[pos/2];
        arr[pos/2]=arr[pos];
        arr[pos]=temp;
        pos=pos/2;
    }

    return;
}

void restoredown(int arr[], int i, int pos);

void delete1(int arr[], int *pos)
{
    cout<<"Deleted value: "<<arr[1]<<" "<<endl;
    arr[1]=arr[*pos];
    int i=1;
    *pos -= 1;
    restoredown(arr, i, *pos);
}

void restoredown(int arr[], int i, int pos)
{
    int lchild=2*i, rchild=2*i+1;
    int check=arr[i];
    while (rchild<=pos)
    {
        if (check>=arr[lchild] && check>=arr[rchild])
        {
            arr[i]=check;
            return;
        }
        else if ( arr[lchild] > arr[rchild])
        {
            arr[i]=arr[lchild];
            i=lchild;
        }
        else if (arr[rchild > check])
        {
            arr[i]=arr[rchild];
            i=rchild;
        }
        lchild=2*i;
        rchild=2*i+1;
    }
    if (lchild==pos && check<arr[lchild])
    {
        arr[i]=arr[lchild];
        i=lchild;
    }
    arr[i]=check;
}

void display(int arr[], int pos)
{
    for (int i=1;i<=pos;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[10001]={INT_MAX};
    int pos=0;
    insert(2, arr, &pos);
    insert(4, arr, &pos);
    insert(6, arr, &pos);
    cout<<"Heap created so far: ";
    display(arr, pos);
    insert(1, arr, &pos);
    insert(3, arr, &pos);
    cout<<"Heap created so far: ";
    display(arr, pos);
    delete1(arr, &pos);
    cout<<"Resulting Heap: ";
    display(arr, pos);
}
