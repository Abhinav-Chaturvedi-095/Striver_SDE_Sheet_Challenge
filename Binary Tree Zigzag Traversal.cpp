/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/
#include<stack>
void Traversal(BinaryTreeNode<int> *root,vector<int>&ans){
    if(!root)
        return ;
    stack<BinaryTreeNode<int>*> currlvl;
    stack<BinaryTreeNode<int>*> nextlvl;
    
    currlvl.push(root);
    bool lefttoright = true;
    while (!currlvl.empty()) {
 
        // pop out of stack
        BinaryTreeNode<int>* temp = currlvl.top();
        currlvl.pop();
 
        // if not null
        if (temp) {
 
            ans.push_back(temp->data); 
            // store data according to current order.
            if (lefttoright) {
                if (temp->left)
                    nextlvl.push(temp->left);
                if (temp->right)
                    nextlvl.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlvl.push(temp->right);
                if (temp->left)
                    nextlvl.push(temp->left);
            }
        }
 
        if (currlvl.empty()) {
            lefttoright = !lefttoright;
            swap(currlvl, nextlvl);
        }
    }
    
}
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    Traversal(root,ans);
    return ans;
}
