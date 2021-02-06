#include <iostream>

using namespace std;

class Queue
{
private:
    int arr[10];
    int fron;
    int rear;

public:
    Queue()
    {
        fron = rear = -1;
        for (int i=0;i<10;i++)
        {
            arr[i]=0;
        }
    }
    void enqueue(int x)
    {
        if (rear==9)
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        else
        {
            arr[rear+1]=x;
            rear++;
        }
    }
    void dequeue()
    {
        if (fron==rear)
        {
            cout<<"Queue is already empty."<<endl;
            return;
        }
        else
        {
            arr[fron+1]=0;
            fron++;
        }
    }
    void isempty()
    {
        if (fron==rear)
        {
            cout<<"Queue is empty."<<endl;
        }
        else{cout<<"Not Empty."<<endl;}
    }
    void isfull()
    {
        if (rear==(sizeof(arr)/sizeof(int))-1)
        {
            cout<<"queue is full."<<endl;
        }
        else
        {
            cout<<"Not Full."<<endl;

        }
    }
    void display()
    {
        for (int i=fron+1;i<=rear;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};
int main()
{
    class Queue q;
    q.isempty();
    q.isfull();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.isempty();
    q.dequeue();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(1);
    cout<<"Displaying whole queue:"<<endl;
    q.display();
    cout<<"Checking isfull() function.";
    q.isfull();

}
