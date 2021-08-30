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

// Using height of a binary tree concept
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;
        return balance(root) != -1;
    }
    
    int balance(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = balance(root->left);
        if(left == -1) return -1;
        
        int right = balance(root->right);
        if(right == -1) return -1;
        
        if(abs(left-right) > 1) return -1;          // the height shold be 0 or 1;
        
        return 1+max(left,right);
    }
};
