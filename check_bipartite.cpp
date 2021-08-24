#include <bits/stdc++.h>

using namespace std;

bool bfs(int node,vector<int> adj[],vector<int>& colour){
    queue<int> q;
    colour[node] = 0;
    q.push(node);
    
    while(!q.empty()){
        int first = q.front();
        q.pop();
        for(auto x : adj[first]){
            if(colour[x] == -1){
                colour[x] = 1 - colour[first];
                q.push(x);
            }
            else if(colour[x] == colour[first]) return false;
        }
    }
    return true;
}

bool Bipartite_graph(vector<int> adj[],int V){
    vector<int> colour(V+1,-1);
    for(int i=1;i<=V;i++){
        if(colour[i] == -1){
            if(!bfs(i,adj,colour)) return false;
        }
    }
    return true;
}

int main()
{
    // n -> nodes and m -> no of edges
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