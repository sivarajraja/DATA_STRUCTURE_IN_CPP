#include<iostream>
using namespace std;
#define max 10

char tree[max];

void root(char key)
{
    if(tree[0] != '\0')
    {
        cout<<"already a tree has a root node!"<<endl;
    }
    else
    {
        tree[0] = key;
    }
    
}

int left_node(char key ,int parent)
{
    if(tree[parent] == '\0')
    {
        cout<<"the parent node"<<tree[(parent*2)+1]<<" not found\n";
    }

    else
    {
        tree[(parent*2)+1] = key;
    }
    return 0;

}

int right_node(char key, int parent)
{
    if(tree[parent] == '\0')
    {
        cout<<"the parent node"<<tree[(parent*2)+1]<<" not found\n";
    }

    else
    {
        tree[(parent*2)+1] = key;
    }
    return 0;
    
}

int print_tree()
{
    cout<<"\n";

    if(tree[0] != '\0')
    {
        for(int i=0; i<max; i++)
        {
            if(tree[i] != '\0')
            {
                cout<<tree[i]<<"- ";
            }

            else
            {
                cout<<"# ";
            }
            
        }
    }

    else
      cout<<"tree is empty!"<<endl;

    return 0;
}

int main()
{
    root('A');
    right_node('C', 0);
    left_node('D', 1);
    right_node('E', 1);
    right_node('F', 2);
    print_tree();

    return 0;
}