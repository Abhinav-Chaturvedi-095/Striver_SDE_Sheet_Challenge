/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode  < int > * root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int sum = 0;
    if(root->left!=NULL)
        sum+=root->left->data;
    if(root->right!=NULL)
        sum+=root->right->data;
    if(root->data>sum)
    {
        if(root->left!=NULL)
            root->left->data = root->data;
        if(root->right!=NULL)
            root->right->data = root->data;
    }
    int leftVal = solve(root->left);
    int rightVal = solve(root->right);

    root->data = leftVal+rightVal;
    return root->data;
}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    solve(root);
}  
