#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

void printval(node *node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}

bool search(node *head, int x)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data == x)
            cout<<"\nTHE ELEMENT "<<x<<" IS SEARCHED IN THE LINKED LIST ! "<<endl;

          temp=temp->next;
        
    }

    return 0;
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = NULL;

    printval(head);
    search(head,22);

    return 0;
}