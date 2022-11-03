#include<iostream>
using namespace std;

class node
{
    public:

    int data;
    node *left;
    node *right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};

int main()
{
    node *n1 = new node(1);
    n1->left = new node(2);
    n1->right = new node(3);
    n1->left->left = new node(4);

    cout<<n1->left->left->data;

    return 0;
}