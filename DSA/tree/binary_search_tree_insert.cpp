#include<iostream>
using namespace std;

class BST
{
    public:
      int data;
      BST *left, *right;

    BST()
    {
        data = 0;
        left=right=NULL;
    }

    BST(int value)
    {
        data = value;
        left=right=NULL;
    }

    int in_order(BST *root)
    {
        if(root==NULL)
           return 0;

        in_order(root->left);
        cout<<root->data<<endl;
        in_order(root->right);

        return 0;
    }

    BST *insert(BST *root, int value)
    {
        if(root==NULL)
          return new BST(value);

        if(value < root->data)
          root->left = insert(root->left,value);

        else if(value > root->data)
          root->right = insert(root->right,value);

        return root;

    }

};

int main()
{
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
 
    b.in_order(root);

    return 0;
}