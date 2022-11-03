#include<iostream>
using namespace std;

class queue_node
{
    public:
     int data;
     queue_node *next;

};

class queue
{
    public:
     queue_node *front, *rear;

    queue()
    {
        front = rear = NULL;
    }

    void enqueue(int val)
    {
        queue_node *temp = new queue_node();
        temp->data = val;
        temp->next = NULL;

        if(rear == NULL)
        {   
            front = rear = temp;
        }

        rear->next=temp;
        rear=temp;

    }

    int dequeue()
    {
        if(front == NULL)
        {
            cout<<"No elements in queue!\n";
            return 0;
        }

        queue_node *temp = front;
        front=front->next;

        if(front == NULL)
        {
            cout<<"queue is empty!\n";
            rear = NULL;
        }

        delete (temp);
        return 0;
    }

};

int main()
{
    queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(40);
    q1.dequeue();
    q1.enqueue(50);

    cout<<"front value = "<<(q1.front)->data<<endl;
    cout<<"rear value = "<<(q1.rear)->data<<endl;

    return 0;
}