/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void InOrder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
//         ans.push_back(-1);
        return;        
    }
   
    InOrder(root->left,ans);
    ans.push_back(root->data);
    InOrder(root->right,ans);
}

void PreOrder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
//         ans.push_back(-1);
        return;        
    }
    
    ans.push_back(root->data);
    PreOrder(root->left,ans);
    PreOrder(root->right,ans);
}

void PostOrder(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
//         ans.push_back(-1);
        return;        
    }
   
    PostOrder(root->left,ans);
    PostOrder(root->right,ans);
    ans.push_back(root->data);

}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    vector<int> temp_in;
    vector<int> temp_pre;
    vector<int> temp_post;
    InOrder(root,temp_in);
    PreOrder(root,temp_pre);
    PostOrder(root,temp_post);
    ans.push_back(temp_in);
    ans.push_back(temp_pre);
    ans.push_back(temp_post);
    
    return ans;
}
