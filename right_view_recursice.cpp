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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        rightview(ans,root,level);
        return ans;
    }
    
    void rightview(vector<int> &ans,TreeNode* root,int level){
        if(root == NULL) return;
        // smart trick if again of the same level we wont consider the value.
        if(ans.size() == level) ans.push_back(root->val); 

        // Root,left,right;     for left view;
        // Root,right,left;     for right view;
        if(root->right) rightview(ans,root->right,level+1);                
        if(root->left) rightview(ans,root->left,level+1);
    }
};
