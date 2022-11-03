#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left , *right;
};

struct node *new_node(int val)
{
    struct node *new_Node = (struct node*) malloc(sizeof(struct node));
    new_Node->data = val;
    new_Node->left = NULL;
    new_Node->right = NULL;

    return(new_Node);
}

int max(int a, int b)
{
    return (a>b) ? a:b;
}

int height(struct node *node)
{
    if(node==NULL)
       return 0;

    return 1 + max(height(node->left) , height(node->right));

}

int diameter(struct node* tree)
{
    if(tree==NULL)
       return 0;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    int left_diameter = diameter(tree->left);
    int right_diameter = diameter(tree->right);

    return max(left_height + right_height + 1 , max(left_diameter , right_diameter));

}

int main()
{
    struct node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
 
    cout << "Diameter of the given binary tree is " <<
        diameter(root);

    return 0;
}