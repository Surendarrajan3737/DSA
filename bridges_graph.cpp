// forward edge -> path to reach that node
// back edge -> when a node does'nt uses anscester edge to reach // simply called as (kuruku valli)Tamil;

#include <bits/stdc++.h>

using namespace std;

void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &intime,vector<int> &lowtime,int &timer){
    vis[node] = 1;
    intime[node] = lowtime[node] = timer++;

    for(auto x : adj[node]){
        if(x == parent) continue;
        if(!vis[x]){
            // child edge is forward edge 
            
            dfs(x,node,adj,vis,intime,lowtime,timer);
            lowtime[node] = min(lowtime[node],lowtime[x]);
            // to check bridge
            if(lowtime[x] > intime[node]){
                cout << node << '-' << x << " is a Bridge"; 
            }
        }
        else{  
            // child is a back edge  
            // this shows that the nodes is reached throgh differnt path not using the kuruku valli
            lowtime[node] = min(lowtime[node],intime[x]);
        }
    } 
}

void bridges(vector<int> adj[],int V){
    vector<int> intime(V,-1);
    vector<int> lowtime(V,-1);
    vector<int> vis(V,0);
    int timer = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,intime,lowtime,timer);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bridges(adj,n);
    return 0;
}
