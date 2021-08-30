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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
        q.push(root);
        bool flag = 0;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();   
                
                // flag == 0 ? level[i] = node->val : level[size-1-i];
                int index = (flag == 0) ? i : size-1-i;
                level[index] = node->val;
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
            }
            flag = !flag;           // This will revert the flag value for each levels
            ans.push_back(level);
        }
        return ans;
    }
};
