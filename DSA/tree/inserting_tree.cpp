#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* create_node(int val)
{
    node *newNode = new node();

    if(!newNode)
    {
        cout<<"memory error\n";
        return 0;
    }

    newNode->data = val;
    newNode->left = newNode->right = NULL;

    return newNode;
}

node *insertion(node *root, int val)
{
    if(root==NULL)
    {
        create_node(val);
        return root;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        
        else
        {
            temp->left = create_node(val);
            return root;
        }

        if(temp->right != NULL)
            q.push(temp->right);
        
        else
        {
            temp->right = create_node(val);
            return root;
        }
        
        cout<<"assigned"<<endl;

    }
    return 0;

}

void display(node *temp)
{
 
    if(temp == NULL)
    {
        cout<<"node is empty \n";
    }

    display(temp->left);
    cout<<temp->data<<" "<<endl;
    display(temp->right);
}

int main()
{
    struct node *root = create_node(10);
    root->left = create_node(11);
    root->left->left = create_node(7);
    root->right = create_node(9);
    root->right->left = create_node(15);
    root->right->right = create_node(8);


    cout << "display traversal before insertion: ";
    display(root);
    cout << endl;

    int key = 12;
    root = insertion(root, key);

    cout << "display traversal after insertion: ";
    display(root);
    cout << endl;

    return 0;
}