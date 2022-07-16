/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
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
struct SubTreeInfo
{
    int min, max;
    int size;
    bool isBST; 
    SubTreeInfo(int min, int max, int size, bool isBST){
        this->min = min;
        this->max = max;
        this->size = size;
        this->isBST = isBST;
    }
};

SubTreeInfo* findLargestBST(TreeNode<int>* root)
{
    if (root == nullptr) {
        return new SubTreeInfo(INT_MAX, INT_MIN, 0, true);
    }
 
    SubTreeInfo* left = findLargestBST(root->left);
    SubTreeInfo* right = findLargestBST(root->right);
 
    SubTreeInfo* info = nullptr;
 
    if (left->isBST && right->isBST && (root->data > left->max && root->data < right->min))
        info = new SubTreeInfo(min(root->data, min(left->min, right->min)),max(root->data, max(left->max, right->max)),left->size + 1 + right->size,true);
    
    else 
        info = new SubTreeInfo(0, 0,max(left->size, right->size),false); 
    
    delete(left), delete(right);
    return info;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
     return findLargestBST(root)->size;
}


// int size(TreeNode<int>* root){
//     if (root == NULL)
//         return 0;
//     return size(root->left) + 1 + size(root->right);
// }

// bool isBST(TreeNode<int>* node, int min, int max){
//     if (node == NULL)
//         return true;
//     if (node->data < min || node->data > max)
//         return false;
//     return isBST(node->left, min, node->data) && isBST(node->right, node->data, max);
// }

// int largestBST(TreeNode<int>* root) 
// {
//     // Write your code here.
//     if (isBST(root, INT_MIN, INT_MAX))
//         return size(root);
 
//     return max(largestBST(root->left), largestBST(root->right));
// }
