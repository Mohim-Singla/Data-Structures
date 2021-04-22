#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack
{
private:
    int arr[5];
    int top;
public:
    Stack()
    {
        top=-1;
        for (int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    void isEmpty()
    {
        if (top==-1)
            cout<<"Stack is Empty."<<endl;
        else
            cout<<"Stack is not empty."<<endl;
    }
    void isfull()
    {
        if (top==4)
            cout<<"Stack is full."<<endl;
        else
            cout<<"stack is not full."<<endl;
    }
    void push(int x)
    {
        if (top==4)
            cout<<"Stack Overflow."<<endl;
        else
        {
            arr[top+1]=x;
            top++;
        }
    }
    void pop()
    {
        if (top==-1)
            cout<<"Stack Underflow."<<endl;
        else
        {
            arr[top]=0;
            top--;
        }
    }
    void top1()
    {
        if (top==-1)
        {
            cout<<"Empty Stack";
        }
        else
        {
            cout<<"Top element in the stack is: "<<arr[top]<<endl;
        }
    }
    void count()
    {
        cout<<"Number of elements in the stack are: "<<top+1<<endl;
    }
    void peek(int position)
    {
        cout<<"Element at position "<<position<<" is: "<<arr[position-1];
    }
    void change(int position, int x)
    {
        arr[position-1]=x;
    }
    void display()
    {
        for (int i=top;i>=0;i--)
        {
            if (top==-1)
                cout<<"Empty Stack."<<endl;
            else
            {
                cout<<arr[i]<<endl;
                continue;
            }
        }
    }
};

int main()
{
    Stack s1;
    s1.isEmpty();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    s1.push(4);
    s1.push(5);
    s1.display();
    cout<<"Using change function: "<<endl;
    s1.change(3, 3);
    s1.display();
    s1.count();
    s1.top1();
    s1.peek(2);

}

