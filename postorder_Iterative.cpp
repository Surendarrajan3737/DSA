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
        stack<TreeNode*> s;
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        TreeNode* node = root;
        TreeNode* temp;
        
        while(node != NULL || !s.empty()){
            if(node != NULL){
                s.push(node);
                node = node->left;
            }
            else{
                temp = s.top()->right;
                if(temp == NULL){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && s.top()->right == temp){
                        temp = s.top();
                        ans.push_back(temp->val);
                        s.pop();
                    }
                }
                else
                    node = temp;
            }
        }
        
        return ans;
    }
};
