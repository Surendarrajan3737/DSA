// kahn's Algorithms to find Topological sort using BFS technique 

class Solution
{
    public:
	//Function to return list containing vertices in Topological order. 
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto x : adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0) 
	            q.push(i);
	    }
	    
	    int cnt =0;
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        ans.push_back(node);
	        for(auto x : adj[node]){
	            indegree[x]--;
	            if(indegree[x] == 0)
	                q.push(x);
	        }
	    }
	    
	    if(cnt == V) return false;
	    return true;
	}
};
