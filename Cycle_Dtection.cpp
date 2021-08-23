# DFS is uded to detect cycle in undirected graph;
class Solution 
{
    public:
    bool dfs(int node,int parent,vector<int> &vis,vector<int> adj[]){
        vis[node] = 1;
        
        for(auto x : adj[node]){
            if(!vis[x]){
                if(dfs(x,node,vis,adj)) return true;        // At final case if we detect cycle it returns true which eventually returns true.
            }
            else if(x != parent) return true;      // returns true to previous function
        }
        
        return false;
    }
    
    
  public:
  //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1,0);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        
        return false;
	    
	}
};
