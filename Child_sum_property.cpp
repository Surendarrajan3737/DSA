/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode* root) {
//     Child sum property;
//     leftchild+rightchild -> parentnode
    if(root == NULL) return 0;
    
    if(root->left) int left_val = root->left->data;
    if(root->right) int right_val = root->right->data;
    
    if(root->data > left_val + right_val){
        if(root->left) 
            root->left->data = root->val;
        if(root->right)
            root->right->data = root->data;
    }
    else{
//      root->data < left and right sum 
        root->data = left_sum + right_sum;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int total = 0;
    if(root->left)  total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) 
        root->data = total;
}  
