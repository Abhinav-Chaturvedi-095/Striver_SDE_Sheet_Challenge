/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool isMirror(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(root1==NULL && root2 == NULL)
        return true;
    if(root1 && root2 && root1->data==root2->data) return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    return false;

}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    return isMirror(root,root);
    
}
