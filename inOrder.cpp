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
//Inorder =>  left root right 
void InOrder(TreeNode *root,vector<int> &ans){
    if(root==NULL){
//         ans.push_back(-1);
        return;        
    }
   
    InOrder(root->left,ans);
    ans.push_back(root->data);
    InOrder(root->right,ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    InOrder(root,ans);
    return ans;
}
