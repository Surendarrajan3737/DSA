class Solution{
	public:
	void dfs(int node,vector<int> &vis,stack<int> &s,vector<int> adj[]){
	    vis[node] = 1;
	    for(auto x : adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,s,adj);
	        }
	    }
	    s.push(node);
	}
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V,0);
	    stack<int> s;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,s,adj);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};
