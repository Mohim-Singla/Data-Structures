#include <iostream>
#include <stack>
#include <string>

using namespace std;

void parenthcheck(string s)
{
    stack<char> oper;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            oper.push(s[i]);
        }
        else if (s[i]==')' || s[i]==']' || s[i]=='}')
        {
            if (oper.empty())
            {
                cout<<"Unbalanced Parenthesis";
                return;
            }
            else
            {
                if ((s[i]==')' && oper.top()=='(') || (s[i]==']' && oper.top()=='[') || (s[i]=='}' && oper.top()=='{'))
                    oper.pop();
                else
                {
                    cout<<"Unbalanced Parenthesis";
                    return;
                }


            }
        }
        else
        {
            continue;
        }
    }
    if (oper.empty())
    {
        cout<<"Balanced Parenthesis";
    }
    else
    {
        cout<<"Unbalanced Parenthesis";
    }
}

int main()
{
    string s;
    cout<<"enter string: ";
    cin>>s;
    parenthcheck(s);
}
