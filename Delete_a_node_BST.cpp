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
    TreeNode* rightleft_most_node(TreeNode* node){
        if(node->left == NULL) 
            return node;
        return rightleft_most_node(node->left);
    }
    
    TreeNode* helper(TreeNode* node){
        if(node->left == NULL) return node->right;
        if(node->right == NULL) return node->left;
        
        TreeNode* left_child = node->left;
        TreeNode* last_left = rightleft_most_node(node->right);
        last_left->left = left_child; 
        return node->right;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* node = root;
        while(node){
            if(node->val > key){
                if(node->left != NULL && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }   
            }
            else{
//                 node val < key
//                 move right
                if(node->right != NULL && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
        }
        
        return root;
    }
};
