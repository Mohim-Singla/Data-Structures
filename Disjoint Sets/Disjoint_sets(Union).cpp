#include <bits/stdc++.h>

using namespace std;

int find(int arr[], int i)
{
    if (arr[i]==-1)
    {
        return i;
    }

    return find(arr, arr[i]);
}

void union_fun(int arr[], int first, int second)
{
    int abs_par1=find(arr, first);
    int abs_par2=find(arr, second);

    if (abs_par1==abs_par2)
    {
        return;
    }

    arr[abs_par1]=abs_par2;
    return;
}

int main()
{
    int arr[10];
    memset(arr, -1, 10);
    cout<<"Enter parent of array elemets: ";
    for (int i=0;i<10;i++)
    {
        cin>>arr[i];
    }

    int y=4;
    int test1, test2;

    while(y--)
    {
        cout<<"Enter elements to be checked: ";
        cin>>test1>>test2;
        int check1=find(arr, test1),check2=find(arr, test2);
        if (check1==check2)
        {
            cout<<test1<<" and "<<test2<<" belong to same set."<<endl;
        }
        else{
            cout<<test1<<" and "<<test2<<" belong to different set."<<endl;
        }
        union_fun(arr, check1, check2);
    }


}
