#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    vector<vector<int>> edges;

    for(int i=0;i<q;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    vector<int> dist(n+1,INT_MAX);
    dist[1] = 0;   // source node

    // Relax edges (n-1 times)
    for(int i=1;i<=n-1;i++)
    {
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for(auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout<<"Negative cycle detected\n";
            return 0;
        }
    }

    // Print shortest distances
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance from 1 to "<<i<<" = "<<dist[i]<<endl;
    }
}