#include<bits/stdc++.h>
using namespace std;

class graph
{
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void add_edges(int x, int y)
    {
        adj[x].push_back(y);
    }

    void DFS(int v)
    {
        list<int> :: iterator i;
        visited[v] = true;
        cout<<v<<" ";

        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
              DFS(*i);
        }
    }

};

int main()
{
    graph g;
    g.add_edges(0, 1);
    g.add_edges(0, 2);
    g.add_edges(1, 2);
    g.add_edges(2, 0);
    g.add_edges(2, 3);
    g.add_edges(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}