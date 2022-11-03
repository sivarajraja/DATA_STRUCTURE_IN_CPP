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

node *new_node(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;

    return Node;
}

int find_height(node *root)
{
    if(root == NULL)
      return 0;

    return root->height;

}

int max(int a, int b)
{
    return (a<b)? a:b ; 
}

int balance_factor(node *root)
{
    if(root == NULL)
      return -1;

    return find_height(root->left) - find_height(root->right);
}

void traversal(node *root)
{
    if(root!=NULL)
    {
        cout<<" "<<root->data;
        traversal(root->left);
        traversal(root->right);
    }
}

node *find_deepest(node *root)
{
    node *temp = root;

    while(temp!=NULL)
    {
        temp=temp->left;
    }

    return temp;
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

node *insert(node *root, int data)
{
    if(root == NULL)
      return new_node(data);

    else if (data<root->data)
    root->left = insert(root->left , data);

    else if (data>root->data)
    root->right = insert(root->right , data);

    else
      return root;

    root->height = max(find_height(root->left), find_height(root->right)) +1;

    int balance = balance_factor(root);

    // LL CASE

    if(balance > 1 && data < root->left->data)
    {
        return right_rotate(root);
    }

    // LR CASE

    if(balance > 1 && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RR CASE

    if(balance < -1 && data > root->right->data)
    {
        return left_rotate(root);
    }

    // RL CASE

    if(balance < -1 && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;

}

node *deletion(node *root, int data)
{

    if(root == NULL)
      return root;

    else if(data < root->data)
      root->left = deletion(root->left, data);

    else if(data > root->data)
      root->right = deletion(root->right, data);

    else if(root->data == data)
    {
        if (root->left==NULL && root->right==NULL)
            root = NULL;

        else if (root->left==NULL)
            root = root->right;

        else if(root->right==NULL)
           root = root->left;

        else
        {
            node *temp = find_deepest(root->right);

            root->data = temp->data;

            root->right = deletion(root->right, temp->data);
        }

        root->height = max(find_height(root->left), find_height(root->right)) +1;

    int balance = balance_factor(root);

    // LL CASE

    if(balance > 1 && data < root->left->data)
    {
        return right_rotate(root);
    }

    // LR CASE

    if(balance > 1 && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RR CASE

    if(balance < -1 && data > root->right->data)
    {
        return left_rotate(root);
    }

    // RL CASE

    if(balance < -1 && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
        
        
    }

    else
    {
        cout<<"the data "<<root->data<<" is not match in the AVL tree please check the data!!!\n";
        return root;
    }

    return root;
    
}

int main()
{
    
    node *root = NULL;
 
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    cout << "Preorder traversal of the constructed AVL tree is \n";
    traversal(root);
 
    root = deletion(root, 10);

     cout << "\nPreorder traversal after deletion of 10 \n";
    traversal(root);

    return 0;
}