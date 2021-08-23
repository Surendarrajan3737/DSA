// Using bfs approach for detecting cycle in a undirected graph

class Solution 
{
    public:
    bool bfs(int node,int parent,vector<int>& vis,vector<int> adj[]){
        queue<pair<int,int>> q;
        vis[node] = 1;
        q.push({node,parent});
        
        while(!q.empty()){
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
            
            for(auto x : adj[first]){
                if(!vis[x]){
                    q.push({x,first});
                    vis[node] = 1;
                }
                else if(x != second) return true;
            }
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
	            if(bfs(i,-1,vis,adj)) return true;
	        }
	    }
	    
	    return false;
	}
};
