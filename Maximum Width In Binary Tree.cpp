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
//level order traversal
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL)
        return 0;
    int result =0;
    queue<TreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int count =q.size();
        result = max(count,result);
        while(count--){
            TreeNode<int>* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return result;
}
