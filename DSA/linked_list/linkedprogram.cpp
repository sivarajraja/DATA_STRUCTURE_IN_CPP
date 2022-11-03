#include<iostream>
using namespace std;

class node      //class for a new node
{
    public:
    int data;
    node *next;
};


void front(node **head_ref, int data_name)      // function for add node in front of linked list
{
    node *new_node = new node();                //creating a new node

    new_node->data = data_name;                 //assigning a data

    new_node->next = (*head_ref);

    (*head_ref) = new_node;                       //make a new node as a head

}

void between(node *previous_next, int data_name)
{
    if(previous_next == NULL)
    {
        cout<<"the previous node can be null !!!!"<<endl;
        return;
    }

     node * new_node = new node();

     new_node->data = data_name;

     new_node->next = previous_next->next;

     previous_next->next = new_node;

}

void back(node **head_ref, int data_name)
{
    node *new_node = new node();
    node *test= *head_ref;

    new_node->data = data_name;

    new_node->next = NULL;

    test->next = new_node;


}

void printnode(node *node)
{
    while(node->next != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main()
{
    node *head = NULL;
     
    front(&head , 3);
    between(head, 8);
    between(head, 11);
    between(head, 13);
    between(head, 16);
    back(&head , 22);
     
    cout<<"Created Linked list is: ";
    printnode(head);

    return 0;
}