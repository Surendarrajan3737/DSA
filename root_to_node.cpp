/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool getpath(TreeNode* node,vector<int> &ans,int B){
    if(node == NULL) return false;

    ans.push_back(node->val);

    if(node->val == B) return true;

    if(getpath(node->left,ans,B) || getpath(node->right,ans,B)) return true;
    else{
        ans.pop_back();
        return false;
    }

}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A == NULL) return ans;
    getpath(A,ans,B);
    return ans;
}
