// forward edge -> path to reach that node
// back edge -> when a node does'nt uses anscester edge to reach // simply called as (kuruku valli)Tamil;

#include <bits/stdc++.h>

using namespace std;

void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &intime,vector<int> &lowtime,int &timer,vector<int> &articulation){
    vis[node] = 1;
    intime[node] = lowtime[node] = timer++;
    int child = 0;

    for(auto x : adj[node]){
        if(x == parent) continue;
        if(!vis[x]){
            // child edge is forward edge 
            
            dfs(x,node,adj,vis,intime,lowtime,timer,articulation);
            lowtime[node] = min(lowtime[node],lowtime[x]);

            // to check articulation_point
            if(lowtime[x] >= intime[node] && parent != -1){
                articulation[node] = 1;
            }
            child++;            // gives the number of childs for a node
        }
        else{  
            // child is a back edge  
            // this shows that the nodes is reached throgh differnt path not using the kuruku valli
            lowtime[node] = min(lowtime[node],intime[x]);
        }
    } 

    if(parent == -1 && child > 1){
        articulation[node] = 1;         // This will be only for root node
    }
}

void Articulation_point(vector<int> adj[],int V){
    vector<int> intime(V,-1);
    vector<int> lowtime(V,-1);
    vector<int> articulation(V,0);
    vector<int> vis(V,0);
    int timer = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,intime,lowtime,timer,articulation);
        }
    }

    for(int i=0;i<V;i++){
        if(articulation[i] == 1) cout << i << '\n';
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

    Articulation_point(adj,n);
    return 0;
}
