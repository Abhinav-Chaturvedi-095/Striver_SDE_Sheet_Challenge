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

bool isValidBST(BinaryTreeNode<int>* root, long minval, long maxval){
    if(root==NULL) return true;
    if(root->data>maxval || root->data<minval) return false;
    return isValidBST(root->left,minval,root->data) && isValidBST(root->right,root->data,maxval);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isValidBST(root,INT_MIN,INT_MAX);
}
