#include <bits/stdc++.h>

using namespace std;

//  This gives a topological sorted values in the stack;

//  Y toposort is done  == it is done to reduce the replicability(repetition of values);
void dfs(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &s){
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x.first])
            dfs(x.first,adj,vis,s);
    }
    s.push(node);
}

void shortest_path(vector<pair<int,int>> adj[],int V,int src){
    stack<int> s;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i])
            dfs(i,adj,vis,s);
    }

//   Normal distance calculation
    vector<int> dis(V,INT_MAX);
    dis[src] = 0;
    while(!s.empty()){
        int first = s.top();
        s.pop();
        for(auto x : adj[first]){
            if(dis[first] + x.second < dis[x.first]){
                dis[x.first] = dis[first] + x.second;
            }
        }
    }

    for(int i=0;i<V;i++){
        cout << dis[i] << ' ';
    }
}

int main()
{
    int n,m,src;
    cin >> n >> m >> src;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    shortest_path(adj,n,src);
    return 0;
}
