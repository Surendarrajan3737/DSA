class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        pathfind(root,maxi);
        return maxi;
    }
    
    int pathfind(TreeNode* root,int &maxi){
        if(root == NULL) return 0;
        
        int left = max(0,pathfind(root->left,maxi));
        int right = max(0,pathfind(root->right,maxi));
        
        maxi = max(maxi,(root->val + left + right));
        
        return (root->val) + max(left,right);         // this helps ud to find the maximum path value of the desendants
    }
}
