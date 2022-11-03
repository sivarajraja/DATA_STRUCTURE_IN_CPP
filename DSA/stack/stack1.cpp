#include<iostream>
using namespace std;

int arr[5];
int top=-1;

// stack is defined as LIFO (last in first out)
// stack has three function 1.push 2.pop 3.peek

void push(int val)
{
    if(top==4)
    {
        cout<<"stack is full!\n";
        return;
    }

    arr[++top]=val;
    cout<<"pushed "<<val<<endl;
}

int pop()
{
    if(top==-1)
    {
        cout<<"stack is empty!\n";
        return 0;
    }

    int temp=arr[top--];
    cout<<"popped "<<temp<<endl;
    return temp;

}

int peek()
{
    if(top==-1)
    {
        cout<<"stack is empty!\n";
        return 0;
    }

    int temp=arr[top];
    cout<<"peeked "<<temp<<endl;
    return temp;
}

int main()
{
    push(7);
    push(6);
    peek();
    push(5);
    push(4);
    push(3);
    pop();
    push(2);
    pop();
    push(1);
    
    return 0;
}