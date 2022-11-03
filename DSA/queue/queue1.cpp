#include<iostream>
using namespace std;
#define MAX 11

class Queue
{
    public:
     int arr[MAX];
     int front=0,rear=-1;


void isfull(Queue *queue)
{
    if(queue->rear==MAX)
        cout<<"queue is full!\n";

    return;
}

void isempty(Queue *queue)
{
    if(queue->rear==-1 || queue->front>queue->rear)
        cout<<"queue is empty!\n";

    return;
}

void enqueue(Queue *queue,int val)
{
    isfull(queue);

    arr[++rear]=val;
    cout<<"enqueued "<<val<<endl;
}

int dequeue(Queue *queue)
{
    isempty(queue);

    int temp=arr[front++];
    return temp;
}

int front_value(Queue *queue)
{
    isempty(queue);

    int temp=arr[front];
    return temp;
}

};

int main()
{
    Queue *Q1 = new Queue();
    Q1->enqueue(Q1,11);
    Q1->enqueue(Q1,22);
    Q1->enqueue(Q1,33);
    Q1->enqueue(Q1,44);

    cout<<"dequeued "<<Q1->dequeue(Q1)<<endl;
    cout<<"dequeued "<<Q1->dequeue(Q1)<<endl;
    cout<<"value of front "<<Q1->front_value(Q1)<<endl;

    return 0;
}