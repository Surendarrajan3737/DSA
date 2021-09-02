/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return " ";
        
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL){
                s += "#,";
            }
            else{
                s += to_string(node->val)+',';
                
            }
            
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == " ") return NULL;
        
        stringstream s(data);
        
//         root value
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* left_node = new TreeNode(stoi(str));
                node->left = left_node;
                q.push(node->left);
            }
            
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* right_node = new TreeNode(stoi(str));
                node->right = right_node;
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
