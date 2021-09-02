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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inmap;
        
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmap);
        
        return root;
    }
    
    TreeNode* buildtree(vector<int> &postorder,int postStart,int postEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inmap){
        
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inroot = inmap[root->val];
        int left_size = inroot - inStart;
        
        root->left = buildtree(postorder,postStart,postStart+left_size-1,inorder,inStart,inroot-1,inmap);
        
        root->right = buildtree(postorder,postStart+left_size,postEnd-1,inorder,inroot+1,inEnd,inmap);
        
        return root;
    }
};
