#include<bits/stdc++.h>
using namespace std;

class graph
{
    public:
     int v; //total vertices of the graph
     vector<list<int>> adj;

     graph(int v);
     void add_edge(int x,int y);
     void BFS(int s);

};

graph :: graph(int v)
{
    this->v = v;
    adj.resize(v);
}

void graph :: add_edge(int x, int y)
{
    adj[x].push_back(y);
}

void graph :: BFS(int s)
{
    vector<bool> visited;       // to check the visited number
    visited.resize(v,false);    //assign all as false 

    list<int> queue;        // list of queue to store the value

    visited[s]=true;        //if visited change to true
    queue.push_back(s);

    while(!queue.empty())
    {
        int value = queue.front();
        cout<<value<<" ";
        queue.pop_front();

        for(auto x:adj[s])
        {
            if(!visited[x])
            {
                visited[x] = true;
                queue.push_back(x);
            }
        }
    }
}

int main()
{
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}