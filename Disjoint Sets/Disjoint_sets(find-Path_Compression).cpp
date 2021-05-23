#include <bits/stdc++.h>

using namespace std;

int find(int arr[], int i)
{
    if (arr[i]==i)
    {
        return i;
    }
    else{
        int x = find(arr, arr[i]);
        arr[i]=x;
        return x;
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
