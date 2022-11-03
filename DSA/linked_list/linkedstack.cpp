#include<iostream>
using namespace std;

class stack_node
{
    public:
      int data;
      stack_node *next;
};

stack_node* new_node(int val)
{
    stack_node* New_node = new stack_node();
    New_node->data = val;
    New_node->next = NULL;
    return New_node;
}

void push(stack_node **node,int val)
{
    stack_node *New_node = new_node(val);
    New_node->next = *node;
    *node = New_node;
    cout<<val<<" is pushed on the stack\n";

}

int pop(stack_node **node)
{
    stack_node *temp = *node;
    *node = (*node)->next;
    int val = temp->data;
    cout<<val<<" is popped from stack\n";
    free(temp);
    return 0;
}

int peek(stack_node* *node)
{
    stack_node *temp = *node;
    cout<<temp->data<<" is the top value\n";
    return 0;
}

int main()
{
    stack_node *node = NULL;

    push(&node,10);
    push(&node,20);
    push(&node,30);
    push(&node,40);
    pop(&node);
    pop(&node);
    peek(&node);
    push(&node,50);
    peek(&node);

    return 0;
}