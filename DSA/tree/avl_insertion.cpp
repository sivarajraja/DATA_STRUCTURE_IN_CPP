#include<iostream>
using namespace std;

class node
{
    public:
      int data;
      node *left;
      node *right;
      int height;
};

node *new_node(int val)
{
    node *Node= new node();
    Node->data= val;
    Node->left= NULL;
    Node->right= NULL;
    Node->height= 1;

    return(Node);
}

int find_height(node *root)
{
    if(root == NULL)
      return 0;

    return root->height;
}

int max(int a, int b)
{
    return (a>b)? a:b;
}

int balance_factor(node *root)
{
    if(root == NULL)
      return 0;

    return find_height(root->left) - find_height(root->right);
}

void traversal(node *root)
{
    if(root != NULL)
    {
        cout<<" "<<root->data;
        traversal(root->left);
        traversal(root->right);
    }
}

node *right_rotate(node *z)
{
    node *y = z->left;
    node *t3 = y->right;

    y->right = z;
    z->left = t3;

    z->height = max(find_height(z->left),find_height(z->right)) + 1;
    y->height = max(find_height(y->left),find_height(y->right)) + 1;

    return y;

}

node *left_rotate(node *z)
{
    node *y = z->right;
    node *t2 = y->left;

    y->left = z;
    z->right = t2;

    z->height = max(find_height(z->left), find_height(z->right)) +1;
    y->height = max(find_height(y->left), find_height(y->right)) +1;

    return y;

}

node *insert(node *root, int val)
{
    if(root == NULL)
      return (new_node(val));

    else if(val<root->data)
    root->left = insert(root->left , val);

    else if(val>root->data)
    root->right = insert(root->right , val);

    else
      return root;

    root->height = max(find_height(root->left), find_height(root->right)) +1;

    int balance = balance_factor(root);

    // LL CASE

    if(balance > 1 && val < root->left->data)
    {
        return right_rotate(root);
    }

    // LR CASE

    if(balance > 1 && val > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RR CASE

    if(balance < -1 && val > root->right->data)
    {
        return left_rotate(root);
    }

    // RL CASE

    if(balance < -1 && val < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;

}

int main()
{
    node *root = NULL;

    root = insert(root ,10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);    

    cout << "Preorder traversal of the constructed AVL tree is \n";
    traversal(root);

    return 0;
}