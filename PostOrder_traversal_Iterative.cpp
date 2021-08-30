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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
      
      // 2 stack Method
      // 1st stack store the root left and right val;
      // 2nd stack store the value in a reverse order;
      
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        
        TreeNode* node;
        
        while(!s1.empty()){
            node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left != NULL) s1.push(node->left);
            if(node->right != NULL) s1.push(node->right);
        }
        
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};
