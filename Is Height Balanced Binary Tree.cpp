/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height(BinaryTreeNode<int>* root){
    int h=0;
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    int left_height;
    int right_height;
     
    if(root==NULL) return true;
    left_height=height(root->left);
    right_height=height(root->right);
    
    if(abs(left_height-right_height)<=1 && isBalancedBT(root->left) && isBalancedBT(root->right) )
        return true;
    return false;
    
}
