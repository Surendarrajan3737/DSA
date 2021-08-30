/************************************************************

    Following is the Binary Tree node structure:
    
    class TreeNode {
        public :
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
            val = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode* node){
    if(node->left == NULL && node->right == NULL) return true;
    return false;
}

void leftboundary(vector<int> &ans,TreeNode* root){
    TreeNode* node = root->left;
    while(node){
    	if(!isleaf(node)) ans.push_back(node->val);
    
    	if(node->left != NULL) node = node->left;
    	else node = node->right;
    }
    
}

void leafNodes(vector<int> &ans,TreeNode* root){
    if(isleaf(root)){
        ans.push_back(root->val);
    }
    if(node->left) leafNodes(ans,root->left);
    if(node->right) leafNodes(ans,root->right);
}

void rightboundary(vector<int> ans,TreeNode* root){
    stack<int> s;
    TreeNode* node = root;
    while(node){
    	if(!isleaf(node)) s.push(node->val);
    
    	if(node->left != NULL) node = node->right;
    	else node = node->left;    
    }
  
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
}

vector<int> traverseBoundary(TreeNode* root){
    vector<int> ans;
    
	//  step1 :    left boundary ecpect leaf
    //  step2 :    leaf nodes using pre or inorder traversal
    //  step3 :    right boundary ecpect leaf in reverse order
    if(!isleaf(root)) ans.push_back(root->val);
    leftboundary(ans,root);
    leafNodes(ans,root);
    rightboundary(ans,root);
    
    return ans;
}
