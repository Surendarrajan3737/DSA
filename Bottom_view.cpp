class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        
        map<int,int> mpp;
        
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                Node* node = q.front().first;
                int vertical = q.front().second;
                q.pop();
                
                mpp[vertical] = node->data;
                
                if(node->left != NULL) q.push({node->left,vertical-1});
                if(node->right != NULL) q.push({node->right,vertical+1});
            }
        }
        
        vector<int> ans;
        
        for(auto x : mpp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};
