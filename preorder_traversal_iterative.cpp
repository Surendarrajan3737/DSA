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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            
        // since it is preorder we need root left right;
            // root
            ans.push_back(node->val);
            
            // right
        // y we pushed right is bacuse the value that we gona pop next is to be left so we need to push right first and then left inorder to pop left val for the next call;
            if(node->right != NULL) s.push(node->right);
            
            // left
            if(node->left != NULL) s.push(node->left);
        }
        return ans;
    }
};
