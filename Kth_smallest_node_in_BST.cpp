/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void Traversal(TreeNode<int>* root,vector<int>& sorted_arr){
    if(!root) 
        return ;
    Traversal(root->left,sorted_arr);
    sorted_arr.push_back(root->data);    
    Traversal(root->right,sorted_arr);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int> sorted_arr;
    Traversal(root,sorted_arr);
    if(sorted_arr.size()<k) return -1;
    return sorted_arr[k-1];
}
