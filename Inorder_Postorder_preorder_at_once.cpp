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
        stack<pair<TreeNode*,int>> s;
        vector<int> pre,in,post;
        
        if(root == NULL) return post;
        s.push({root,1});
        
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            
          // preorder
            if(node.second == 1){
                pre.push_back(node.first->val);
                node.second++;
                s.push(node);
                
                if(node.first->left != NULL) s.push({node.first->left,1});      //[root ,left ],right
            }
          
          //inorder
            else if(node.second == 2){
                in.push_back(node.first->val);
                node.second++;
                s.push(node);
                
                if(node.first->right != NULL) s.push({node.first->right,1});    //left,[root,right]
            }
            else{ // num == 3;
                post.push_back(node.first->val);
            } 
                
        }
        
        return post;
    }
};
