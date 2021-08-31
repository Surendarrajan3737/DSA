/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        
        if(root == NULL) return level;
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(i == size-1) level.push_back(node->val);
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        
        return level;
    }
};
