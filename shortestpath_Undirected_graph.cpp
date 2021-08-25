#include <bits/stdc++.h>

using namespace std;

void shortest_path(vector<int> adj[],int V,int src){
    queue<int> q;
    vector<int> dis(V,INT_MAX);         // Distance array;
    dis[src] = 0;           // This is bacause getting into that first node is constant i.e node 5 -> node 5 = 0;
    q.push(src);
    while(!q.empty()){
        int first = q.front();
        q.pop();
        for(auto x : adj[first]){
            if((dis[first] + 1) < dis[x]){
                dis[x] = dis[first] + 1;
                q.push(x);
            }
        }
    }
    for(int i=0;i<V;i++){
        cout << dis[i] << ' ';
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin >> src;

    shortest_path(adj,n,src);

    return 0;
}
