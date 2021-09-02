// Similar to find nodes at a k distance;

class Solution {
  public:
    
    void findparent(unordered_map<Node*,Node*> &map,Node* root,int target,Node* &tar){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                
                if(node->data == target) tar = node;
                
                if(node->left != NULL){
                    map[node->left] = node;
                    q.push(node->left);
                }
                
                if(node->right != NULL){
                    map[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
  
  
    int minTime(Node* root, int target) 
    {
        Node* tar = NULL;
        unordered_map<Node*,Node*> parent;
        findparent(parent,root,target,tar);
        
        unordered_map<Node*,bool> visited;
        
        queue<Node*> q;
        q.push(tar);
        
        visited[tar] = true;
        int time = -1;
        
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        return time;
    }
};
