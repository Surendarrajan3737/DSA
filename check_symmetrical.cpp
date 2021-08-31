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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        if(check_sym(root->left,root->right)) return true;
        return false;
    }
    
    bool check_sym(TreeNode* left_node,TreeNode* right_node){
//         leaf node;
        if(left_node == NULL || right_node == NULL)
            return left_node == right_node;
        
        if(left_node->val != right_node->val) return false;
        
        return check_sym(left_node->left,right_node->right) &&
            check_sym(left_node->right,right_node->left);
        
    }
    
};
