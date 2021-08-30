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

//Diameter is the longest distance between an two nodes it may or may not pass throught the root node
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; 
        diameter1(root,diameter);
        return diameter;
    }
    
    int diameter1(TreeNode* root,int &diameter) { // pass by refernce
        if(root == NULL) return 0;
        
        int left = diameter1(root->left,diameter);
        int right = diameter1(root->right,diameter);
        
        diameter = max(diameter,left+right);
        
        return 1+max(left,right);
    }          
};
