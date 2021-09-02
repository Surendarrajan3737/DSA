/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();    
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                
                if(node->right != NULL){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//      parent node finding and storing in the map;
        unordered_map<TreeNode*,TreeNode*> parent;
        findparent(parent,root);
        
        unordered_map<TreeNode*,bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            if(cnt++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
//              for upward or parent
                
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true; 
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};
