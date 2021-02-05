#include <iostream>
#include <string>
#include <stack>

using namespace std;

void posttoinfix(string exp)
{
    stack<int> oper;

    for (int i=0;i<exp.length();i++)
    {
        if (exp[i]=='*' || exp[i]=='+' || exp[i]=='/' || exp[i]=='-' || exp[i]=='^')
        {
            int a,b;
            a=oper.top();
            oper.pop();
            b=oper.top();
            oper.pop();

            switch(exp[i])
            {
            case '+':
                {
                    oper.push(b+a);
                    break;
                }
            case '-':
                {
                    oper.push(b-a);
                    break;
                }
            case '*':
                {
                    oper.push(b*a);
                    break;
                }
            case '/':
                {
                    oper.push(b/a);
                    break;
                }
            case '^':
                {
                    oper.push(b^a);
                    break;
                }

            }
        }
        else
        {
            oper.push(exp[i]-'0');
        }

    }
    cout<<oper.top();
}

int main()
{
    string exp= "123+*8+";
    posttoinfix(exp);
}
