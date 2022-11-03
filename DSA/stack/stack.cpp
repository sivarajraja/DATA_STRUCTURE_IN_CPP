#include<iostream>
using namespace std;

class stack
{
    public:
    int size=4;
    int n=0;

    bool full()
    {
        if(n==size-1)
          return true;

        else
         return false;
    }

    void find(int a[],int b)
    {
        if(full())
          cout<<"stack is full";
        
        else 
        {
            a[n]=b;
            n++;
        }
    }

};

int main()
{
    
    stack s1;
    int a[s1.size];

    s1.find(a,1);
    s1.find(a,2);
    s1.find(a,3);
    s1.find(a,4);

    return 0;
}