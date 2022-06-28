/************************************************************
    Following is the Binary Search Tree node structure
    
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
void Traversal(TreeNode<int>* root,vector<int>& sorted_arr){
    if(!root) 
        return ;
    Traversal(root->right,sorted_arr);
    sorted_arr.push_back(root->data);    
    Traversal(root->left,sorted_arr);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> sorted_arr;
    Traversal(root,sorted_arr);
    if(sorted_arr.size()<k) return -1;
//     cout<<sorted_arr.size()<<"\n";
//     for(int i=0;i<k;i++)
//         cout<<sorted_arr[i]<<" ";
//     cout<<"\n";
    return sorted_arr[k-1];
}
