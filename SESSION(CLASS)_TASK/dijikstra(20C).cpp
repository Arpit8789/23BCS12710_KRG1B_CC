#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<q;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,1});   // distance , node

    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        if(d > dist[node]) continue;

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int weight = it.second;

            if(dist[node] + weight < dist[adjNode])
            {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance from 1 to "<<i<<" = "<<dist[i]<<endl;
    }

}