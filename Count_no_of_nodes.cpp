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
    // normal traversal takes O(n) time:
    // This method takes O((log n)^2) time;
    // This method takes O((log n)) space;
    int countNodes(TreeNode* root) {
    // using height of the tree we can able to find the no of nodes
        
        if(root == NULL) return 0;
        
        int height_left = heightleft(root);
        int height_right = heightright(root);
        
        if(height_left == height_right) return ((1<<height_left)-1);
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int heightleft(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    
    int heightright(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};
