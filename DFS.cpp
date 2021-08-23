class Solution(){
    void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &arrdfs){
        arrdfs.push_back(node);
        // adjacency recursive call
        for(auto x : adj[node]){
            if(!vis[x]){
                dfs(x,vis,adj,arrdfs);
            }   
        }
    }

    vector<int>dfsOfGraph(int V, vector<int> adj[]){
	      vector<int> vis(V+1,0);
	      vector<int> arrdfs;
	    
	      for(int i=1;i<=V;i++){
	          if(!vis[i]){
	              dfs(i,vis,adj,arrdfs);
	          }
	      }
	      return arrdfs;
    }
};
