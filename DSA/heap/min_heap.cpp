#include<iostream>
using namespace std;

class node
{
    public:
      int *arr;
      int size;
      int capacity;

    node(int);
    void insert(int);
    int head(int);
    void swap(int * ,int *);
    void print();
};

node :: node(int c) //assign a variable
{
    size = 0;
    capacity = c;
    arr = new int[c];
}

int node :: head(int i)
    {
        int c = (i-1)/2;
        return c;
    }

void node :: swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void node :: insert(int v)
{
    if(size == capacity)
    {
        cout<<"overflow! size is full\n";
    }

    size++;
    int i = size-1;
    arr[i] = v;

    while(i!=0 && arr[head(i)] > arr[i])
    {
            swap(&arr[i], &arr[head(i)]);
            i=head(i);
    }
}

void node :: print()
{
    for(int i=0; i<size; i++)
      cout<<" "<<arr[i];
}


int main()
{
    node n(10);
    n.insert(12);
    n.insert(14);
    n.insert(16);
    n.insert(18);
    n.insert(10);

    n.print();

    return 0;
}