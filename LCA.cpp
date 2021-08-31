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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         base case:
        if(root == NULL || root == p || root == q) {
            return root;      // if we found that any value or NULL return it
        }
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL) return right;     // in anycase NULL can be returned
        else if(right == NULL) return left;
        else{
//             this denotes that we found the reult so return that comon node;
            return root;
        }
    }
};
