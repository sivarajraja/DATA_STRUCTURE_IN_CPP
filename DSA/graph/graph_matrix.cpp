#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"enter the node:\n";
    cin>>n>>m;
    int arr[n+1][n+1];

    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"enter the adjacent node:\n";
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }

    return 0;
}