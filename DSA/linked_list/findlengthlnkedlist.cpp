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

int length(node *head)
{
    int count=0;
    node *temp=head;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;

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

    cout<<" \nLENGTH OF AN LINKED LIST : "<<length(head)<<endl;

    return 0;
}
