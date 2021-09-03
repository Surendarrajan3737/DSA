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
//     recursive solution : 
//     T.C -> o(n);
//     S>C -> o(n);   // stack space in memory due to recursive call
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
//         post order with reversed 
//         right left root;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;         // Before returing poing my right to the prev node
        root->left = NULL;              
        
        prev = root;                // before returing making my cur node as prev such that we can join them in the node right
    }
};
