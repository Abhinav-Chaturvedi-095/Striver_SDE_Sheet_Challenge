/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void traversal(vector<int>& ans,BinaryTreeNode<int> *root){
    if(!root)
        return ;
    traversal(ans,root->left);
    ans.push_back(root->data);
    traversal(ans,root->right);
//     return ans;
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> ans;
    traversal(ans,root);
    int front=0;
    int rear=ans.size()-1;
    while(front<rear){
        if (ans[front] + ans[rear] == k)
            return true;
        if(ans[front] + ans[rear] > k)
            rear--;
        if(ans[front] + ans[rear] < k)
            front++;
    }
    return false;
}
