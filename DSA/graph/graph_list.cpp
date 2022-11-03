#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void print_graph(vector<int> arr[], int v)
{
    
    for(int i=0; i<v; i++)
    {
        cout<<"\n\nadjacent of "<<i<<" is\nhead ";
        for (auto x : arr[i])
          cout<<"-> "<< x;
        printf("\n");
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    insert(adj, 0, 1);
    insert(adj, 0, 4);
    insert(adj, 1, 2);
    insert(adj, 1, 3);
    insert(adj, 1, 4);
    insert(adj, 2, 3);
    insert(adj, 3, 4);
    print_graph(adj, V);

    return 0;
}