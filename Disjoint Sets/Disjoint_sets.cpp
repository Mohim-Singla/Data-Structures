#include <bits/stdc++.h>

using namespace std;

int find(int arr[], int i)
{
    if (arr[i]==-1)
    {
        return i;
    }
    else{
        return find(arr, arr[i]);
    }
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
    while(y--)
    {
        int test1, test2;
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
    }
}
