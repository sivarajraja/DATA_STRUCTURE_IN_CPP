#include<iostream>
#include<stack>
using namespace std;

class queue
{
    public:
    stack<int> s1,s2;

    void enqueue(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(x);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
    }

    int dequeue()
    {
        if(s1.empty())
        {
            cout<<"queue is empty!\n";
            exit(0);
        }

        int x = s1.top();
        s1.pop();
        return x;

    }

};

int main()
{
    queue q1;

    q1.enqueue(10);
    q1.enqueue(11);
    q1.enqueue(12);

    cout<<"dequeued value is "<<q1.dequeue()<<endl;
    cout<<"dequeued value is "<<q1.dequeue()<<endl;

    return 0;
}