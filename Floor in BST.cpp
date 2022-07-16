/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * node, int x)
{
    // Write your code here.
    if (node == NULL) 
        return -1;   
    if (node->val == x) 
        return node->val ;
    
    if (node->val > x) 
        return floorInBST(node->left, x); 
  
    int floor = floorInBST(node->right, x); 
    return (floor <= x  && floor!=-1) ? floor : node->val;
}
