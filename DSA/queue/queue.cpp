#include<iostream>
using namespace std;

int n=5;
int front=0,back=0;

void enqueue(int arr[],int a)
{
    if(back==n-1)
    {
        cout<<"queue is full!"<<endl;
    }
    arr[back]=a;
    back+=1;
}

void dequeue(int arr[])
{
    if(front==back)
    {
        cout<<"queue is empty!";
        front=back=0;
    }
    front+=1;
}

int display(int arr[])
{
    if(front==back)
    {
        cout<<"queue is empty!";
        front=back=0;
    }
    return arr[front];
}

int main()
{
    int arr[n];

    enqueue(arr,3);
    enqueue(arr,3);
    enqueue(arr,3);
    enqueue(arr,3);
    enqueue(arr,3);

    dequeue(arr);
    dequeue(arr);
    dequeue(arr);
    dequeue(arr);
    dequeue(arr);

    enqueue(arr,11);

    cout<<display(arr);

    return 0;
}