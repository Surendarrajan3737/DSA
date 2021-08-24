#include <bits/stdc++.h>

using namespace std;

bool dfs(int node,vector<int> adj[],vector<int> &colour){
    for(auto x : adj[node]){
        if(colour[x] == -1){
            colour[x] = 1 - colour[node];
            if(!dfs(x,adj,colour)) return false;
        }
        else if(colour[x] == colour[node]) return false;
    }
    return true;
}

bool Bipartite_graph(vector<int> adj[],int V){
    vector<int> colour(V,-1);
    for(int i=0;i<V;i++){
        if(colour[i] == -1){
            if(!dfs(i,adj,colour)) return false;
        }
    }
    return true;
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

    if(Bipartite_graph(adj,n)) cout << "It is a bipartite graph" << '\n';
    else cout << "It is not a bipartite graph";
    return 0;
}
