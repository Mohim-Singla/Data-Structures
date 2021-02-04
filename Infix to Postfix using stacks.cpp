#include <iostream>
#include<stack>
#include <string>
using namespace std;

int prec(char x)
{
    if(x=='^')
    return 3;
    else if(x=='*'||x=='/')
    return 2;
    else if(x=='+'||x=='-')
    return 1;
    else
    return -1;
}

void infixtopostfix(string s)
{
    stack<char> oper;
    oper.push('M');
    for(int i=0;i<s.length();i++)
    {
        if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
        {
            cout<<s[i];
        }
        else if (s[i] == '(' )
        {
            oper.push('(');
        }

        else if( s[i] == ')' )
            {
                while(oper.top()!='M' && oper.top()!='(')
                {
                    cout<<oper.top();
                    oper.pop();
                }
                if (oper.top()=='(')
                {
                    oper.pop();
                }

            }
        else
        {
            while (oper.top()!='M' && prec(s[i])<=prec(oper.top()))
                {
                    cout<<oper.top();
                    oper.pop();
                }
                oper.push(s[i]);
        }
    }
    while(oper.top()!='M')
        {
            cout<<oper.top();
            oper.pop();
        }

}

int main()
{
    string str="a+b*(c^d-e)^(f+g*h)-i";

    infixtopostfix(str);
}
