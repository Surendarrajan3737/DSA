#include <bits/stdc++.h>

using namespace std;

void dijkstras_Algo(vector<pair<int,int>> adj[],int V,int src){
    vector<int> dis(V+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;          // min heap creation with pair
    dis[src] = 0;
    q.push({dis[src],src});

    while(!q.empty()){
        int dist = q.top().first;      // dis
        int node = q.top().second;    // node
        q.pop();

        for(auto x : adj[node]){
            int next = x.first;
            int nextwei = x.second;
            if(dis[node] + nextwei < dis[next]){    
                dis[next] = dis[node] + nextwei;
                q.push({dis[next],next});
            }
        }
    }

    for(int i=1;i<V+1;i++){
        cout << dis[i] << ' ';
    }
}

int main()
{
    int n,m,src;
    cin >> n >> m >> src;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstras_Algo(adj,n,src);
    return 0;
} 

