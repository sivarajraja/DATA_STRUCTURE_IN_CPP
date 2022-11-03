#include<iostream>
using namespace std;

class stack
{
    private:
      int top=-1;
      static const int max=100;
      int arr[max];

    public:
      bool isfull();
      bool isempty();
      void push(int x);
      int pop();

};

bool stack::isfull()
{
    if(top==max-1)
      return true;

    return false;
}

bool stack::isempty()
{
    if(top==-1)
      return true;

    return false;
}

void stack::push(int x)
{
    if(isfull())
    {
        cout<<"stack overflow!\n";
    }
    top++;
    arr[top]=x;
}

int stack::pop()
{
    if(isempty())
    {
        cout<<"stack is empty!\n";
    }
    int x =arr[top];
    top--;
    return x;
}

class special_stack:public stack
{
    stack min;
    public:
      int pop();
      void push(int x);
      int getmin();

};

void special_stack :: push(int x)
{
    if(isempty()==true)
    {
        stack::push(x);
        min.push(x);
    }

    else
    {
        stack::push(x);
        int y=min.pop();
        min.push(y);
        if(x<y)
            min.push(x);

        else
            min.push(y);
        
    }
    
}

int special_stack :: pop()
{
    int x = stack::pop();
    min.pop();
    return x;
}

int special_stack :: getmin()
{
    int x=min.pop();
    min.push(x);
    return x;
}

int main()
{
    special_stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getmin() << endl;
    s.push(5);
    cout << s.getmin();

    return 0;
    
}