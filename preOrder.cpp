/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
//Preorder => root left right
void PreOrder(TreeNode *root,vector<int> &ans){
    if(root==NULL){
//         ans.push_back(-1);
        return;        
    }
    
    ans.push_back(root->data);
    PreOrder(root->left,ans);
    PreOrder(root->right,ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    PreOrder(root,ans);
    return ans;
}
