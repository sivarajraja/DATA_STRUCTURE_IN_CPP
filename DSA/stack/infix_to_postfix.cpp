#include<bits/stdc++.h>
using namespace std;

// function for precedence for operators
int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;

    else
        return -1;
}

void infix_to_postfix(string s)
{
    stack<char> cs;
    string result;

    int i;

    for(i=0; i<s.length(); i++)
    {
        char c=s[i];

        // if the word is operand insert into the result
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            result+=c;

        else if(c=='(')
        {
            cs.push('(');
        }

        else if(c==')')
        {
            while(cs.top()!='(')
            {
                result+=cs.top();
                cs.pop();
            }
            cs.pop();
        }

        // this is an operator check the precedence before push into stack
        else
        {
            while(!cs.empty() && (prec(s[i])<=prec(cs.top())))
            {
                result+=cs.top();
                cs.pop();
            }
            cs.push(c);
        }
    }

    // pop all the the element from the stack

    while(!cs.empty())
    {
        result+=cs.top();
        cs.pop();
    }

    cout<<result<<endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    infix_to_postfix(exp);

    return 0;
}