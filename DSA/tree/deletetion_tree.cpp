#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *left , *right;
};

struct node *new_node(int data)
{
    if(!new_node)
    {
        cout<<"memory error!\n";
        return 0;
    }

    struct node *new_Node = new node();
    new_Node->data = data;
    new_Node->left = new_Node->right = NULL;

    return new_Node;

}

void in_order(struct node *root)
{
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void delete_node(struct node* root , struct node* key)
{
    queue<struct node*> q;
    q.push(root);

    while(!q.empty())
    {
        struct node* temp;
        temp = q.front();
        q.pop();

        if(temp == key)
        {
            temp = NULL;
            delete(key);
        }

        if(temp->left)
        {
            if(temp->left == key)
            {
                temp->left = NULL;
                delete(temp->left);

            }

            else
               q.push(temp->left);
            
        }

         if(temp->right)
        {
            if(temp->right == key)
            {
                temp->right = NULL;
                delete(temp->right);
            }

            else
               q.push(temp->right);
            
        }

    }


}

struct node* deletion(struct node *root, int data)
{
    if(root == NULL)
    {
        cout<<"tree is empty\n";
    }

    else if(root->left==NULL && root->right==NULL)
    {
        if(root->data==data)
           return 0;
    }

    struct node *temp;
    struct node *key;

    queue<struct node*> q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == data)
            key=temp;

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);

    }

    if(key==NULL)
    {
        cout<<"wrong! check the key\n";
        return 0;
    }

    else
    {
        int x = temp->data;
        delete_node(root , temp);
        key->data = x;
    }
    
    return 0;
}

int main()
{
    struct node* root = new_node(10);
    root->left = new_node(11);
    root->left->left = new_node(7);
    root->left->right = new_node(12);
    root->right = new_node(9);
    root->right->left = new_node(15);
    root->right->right = new_node(8);
 
    cout << "Inorder traversal before deletion : ";
    in_order(root);
 
    int key = 11;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    in_order(root);
 

    return 0;
}