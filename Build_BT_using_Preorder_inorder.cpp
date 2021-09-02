class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        
        TreeNode* root = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    
    TreeNode* buildtree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> &inmap){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inroot = inmap[root->val];
        int leftsize = inroot - inStart;
        
        root->left = buildtree(preorder,preStart+1,preStart+leftsize,inorder,inStart,inroot-1,inmap);
        root->right =       buildtree(preorder,preStart+leftsize+1,preEnd,inorder,inroot+1,inEnd,inmap);
        
        return root;
    }
};
