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
void dfs(TreeNode<int> *root, int lv, vector<int> &res){
        if(!root)   return;
        if(lv>=res.size()) res.push_back(root->data);
        dfs(root->left,lv+1,res);
        dfs(root->right,lv+1,res);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> res;
    dfs(root, 0, res);
    return res;
}
