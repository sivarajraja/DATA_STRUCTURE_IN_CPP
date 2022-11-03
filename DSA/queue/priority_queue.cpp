#include<iostream>
using namespace std;

typedef struct Node
{
    int value;
    int priority;
    int size;

} node;

   node n[1000];  // assign lesser value

void insert(int v, int p)
{
    node.size++; //increase the node.size
    n[node.size].value = v;
    n[node.size].priority = p;
}

void remove()  //it remove high priority
{
    node temp;
    int num;

    for(int i=0; i<node.size; i++)
    {
        if(n[i].priority > temp.priority)
        {
           temp.value = n[i].value;
           temp.priority = n[i].priority;
           num = i;
        }

        else if (n[i].priority == temp.priority && n[i].value > temp.value)
        {
            temp.value = n[i].value;
            temp.priority = n[i].priority;
            num = i;
        }

    }

    for(int j=num; j<node.size; j++)
    {
        n[j].value = n[j+1].value;
        n[j].priority = n[j+1].priority;
    }

    node.size--;
}

void print()
{
    for(int i=0; i<=node.size; i++)
      cout<<n[i].value<<" "<<endl;
}

int main()
{
    insert(11 , 1);
    insert(22 , 2);
    insert(33 , 3);
    insert(44 , 4);

    remove();
    print();

    return 0;
}