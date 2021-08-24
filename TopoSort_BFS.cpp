// kahn's Algorithms to find Topological sort using BFS technique

class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{  
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto x : adj[i]){
	            indegree[x]++;        // inserting all the indegree values
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0) 
	            q.push(i);            // Initially inserting all the o indegree nodes
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto x : adj[node]){
	            indegree[x]--;
	            if(indegree[x] == 0)      // If the indegree becomes 0 we push it into stack
	                q.push(x);
	        }
	    }
	    
	    return ans;
	}
};
