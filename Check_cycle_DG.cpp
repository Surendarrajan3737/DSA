// Check it is a cycle usign DFS
class Solution
{
    public:
    bool dfs(int node,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto x: adj[node]){
            if(!vis[x]){
                if(dfs(x,vis,dfsvis,adj)) return true;
            }
            else if(dfsvis[x]) return true;
        }
        
        dfsvis[node] = 0;
        return false;
    }
    
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> vis(V,0);
	   	vector<int> dfsvis(V,0);
	   	
	   	for(int i=0;i<V;i++){
	   	    if(!vis[i]){
	   	        if(dfs(i,vis,dfsvis,adj)) return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};
