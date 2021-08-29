#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int> adj[],vector<int> &vis,stack<int> &s){
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x,adj,vis,s);
        }
    }
    s.push(node);
}

void revdfs(int node,vector<int> adj[],vector<int> &vis){
    cout << node << " ";
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            revdfs(x,adj,vis);
        }
    }
}

void scc(vector<int> adj[],int V){
    // step 1 : toposort based on minimum time;
    vector<int> vis(V,0);
    stack<int> s;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,s);
        }
    }

    // step 2 : transpose the graph
    vector<int> transpose[V];
    for(int i=0;i<V;i++){
        vis[i] = 0;
        for(auto x : adj[i]){
            transpose[x].push_back(i);
        }
    }

    // step 3 : dfs on the least time occured node i.e top ele of the stack
    while(!s.empty()){
        int first = s.top();
        s.pop();
        if(!vis[first]){
            cout << "SCC : ";
            revdfs(first,transpose,vis);
            cout << endl;
        }
    }
}

int main()
{
    int N,m;
    cin >> N >> m;
    vector<int> adj[N];
    for(int i=0;i<N;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);            // Directed graph
    }
    scc(adj,N);
    return 0;
}
