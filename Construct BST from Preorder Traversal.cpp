/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<stack>
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);
        TreeNode<int> *p = root;
        stack<TreeNode<int>*> S;
        int i = 1;
        while(i < preOrder.size())
        {
            if(p->data > preOrder[i])
            {
                p->left = new TreeNode<int>(preOrder[i]);
                S.push(p);
                p = p->left;
            }
            else
            {
                while(!S.empty() && S.top()->data < preOrder[i])
                {
                    p = S.top();
                    S.pop();
                }
                p->right = new TreeNode<int>(preOrder[i]);
                p = p->right;
            }
            i++;
        }
        return root;
}
