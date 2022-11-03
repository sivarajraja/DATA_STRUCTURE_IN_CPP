#include<iostream>
using namespace std;

class queue
{
    public:
     int front,rear;
     int size;
     int *arr;

     queue(int s)
     {
        front = rear = -1;
        size = s;
        arr = new int[s];
     }

    void enqueue(int val);
    int dequeue();
    void display();

};

void queue::enqueue(int val)
{
    if(rear==size-1 && front == 0)
    {
        cout<<"queue is full!\n";
    }

    else if (front == -1)
    {
        front = rear = 0;
        arr[rear]=val;
    }

    else if (rear == size-1 && front !=0)
    {
        rear = 0;
        arr[rear]=val;
    }

    else
    {
        rear+=1;
        arr[rear]=val;
    }
    
}

int queue::dequeue()
{
    if(front == -1 && rear == -1)
    {
        cout<<"queue is empty!\n";
        return 0;
    }

    int value = arr[front];
    arr[front] = -1;

    if(front == size-1)
        front = 0;
    
    else if(front == rear)
        front = rear = -1;

    else
       front++;    

    return value;
}

void queue::display()
{
    if(front == -1 && rear == -1)
    {
        cout<<"queue is empty!\n";
    }

    for(int i=front; i<=rear; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    
}

int main()
{
    queue q1(5);
    q1.enqueue(10);
    q1.enqueue(11);
    q1.enqueue(12);

    q1.display();

    cout<<"deleted value "<<q1.dequeue()<<endl;
    cout<<"deleted value "<<q1.dequeue()<<endl;

    q1.display();

    q1.enqueue(13);
    q1.enqueue(14);

    q1.display();

    return 0;
}