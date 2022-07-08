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


TreeNode<int>* arrToBst(vector<int> &arr,int start, int end)
{
    // Write your code here.
     if (start > end)
        return NULL;
 
    int mid = (start + end)/2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
 
    root->left = arrToBst(arr, start,mid - 1);
    root->right = arrToBst(arr, mid + 1, end);
 
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return arrToBst(arr,0,n-1);       
}
