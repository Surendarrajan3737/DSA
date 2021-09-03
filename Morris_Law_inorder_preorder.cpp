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
// Morris Travesal for inorder and preorder
// T.C -> o(n)
// S.C -> o(1)

// Inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* ptr = root;
        vector<int> inorder;
        while(ptr != NULL){
            if(ptr->left == NULL){
                inorder.push_back(ptr->val);
                ptr = ptr->right;
            }
            else{
//                 forming tread
                TreeNode* ptr_2nd = ptr->left;
                while(ptr_2nd->right != NULL && ptr_2nd->right != ptr){
                    ptr_2nd = ptr_2nd->right;
                }
                if(ptr_2nd->right == NULL){
                    ptr_2nd->right = ptr;
                    ptr = ptr->left;
                }
                else if(ptr_2nd->right == ptr){
                    ptr_2nd->right = NULL;
                    inorder.push_back(ptr->val);
                    ptr = ptr->right;
                }
            }
        }
        return inorder;
    }
};


// Preorder

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* ptr = root;
        vector<int> preorder;
        while(ptr != NULL){
            if(ptr->left == NULL){
                preorder.push_back(ptr->val);
                ptr = ptr->right;
            }
            else{
//                 forming tread
                TreeNode* ptr_2nd = ptr->left;
                while(ptr_2nd->right != NULL && ptr_2nd->right != ptr){
                    ptr_2nd = ptr_2nd->right;
                }
                if(ptr_2nd->right == NULL){
                    ptr_2nd->right = ptr;
                    preorder.push_back(ptr->val);
                    ptr = ptr->left;
                }
                else if(ptr_2nd->right == ptr){
                    ptr_2nd->right = NULL;
                    ptr = ptr->right;
                }
            }
        }
        return preorder;
    }
};
