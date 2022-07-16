/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
     if (node == NULL) 
        return -1;   
    if (node->data == x) 
        return node->data; 
    
    if (node->data < x) 
        return findCeil(node->right, x); 
  
    int ceil = findCeil(node->left, x); 
    return (ceil >= x) ? ceil : node->data;
}
