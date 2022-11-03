#include<iostream>
using namespace std;

class node
{
    public:
     int data;
     node *next;
     node *prev;
};

    node *head=NULL;
    node *tail=NULL;

void insert_at_beginning(int val)
{
    node *new_node=new node();
    
    new_node->data=val;
    new_node->prev=NULL;

    if(head==NULL)
    {
        new_node->next=NULL;
        tail=new_node; 
        head=new_node;
    }

    else
    {
        new_node->next=head;
        new_node->next->prev=new_node;
        head=new_node;
    }
    
    cout<<"inserted "<<val<<" at the beginning"<<endl;
}

void display()
{
    node *temp=head;
    cout<<endl;

    cout<<"\n VALUE : ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void rev_display()
{
    node *temp=tail;
    cout<<endl<<"\n";
    cout<<"\n REVERSE VALUE : ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}

int main()
{
    node *head=NULL;
    node *tail=NULL;

    insert_at_beginning(4);
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(1);

    display();
    rev_display();

    return 0;

}