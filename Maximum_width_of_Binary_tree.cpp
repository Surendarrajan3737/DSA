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
    int widthOfBinaryTree(TreeNode* root) {
//         level order traversal
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        int first,last,ans=0;
        
        while(!q.empty()){
            int size = q.size();
            int min_index = q.front().second;   
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int cur_index = q.front().second;
                q.pop();
                cur_index = cur_index - min_index;      // To avoid integer/index overflow 
                
                if(i == 0) first = cur_index;
                if(i == size-1) last = cur_index;
                
                //based on array indexing or segment trees.
                if(node->left != NULL) q.push({node->left,2*cur_index+1});  
                if(node->right != NULL) q.push({node->right,2*cur_index+2});
            }
            ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};
