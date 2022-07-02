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
#include<bits/stdc++.h>
TreeNode<int> * constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp) {
    
  if (preStart > preEnd || inStart > inEnd) return NULL;

    int curr=preorder[preStart];
  TreeNode<int> * root = new TreeNode<int>(curr);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem,inorder,inStart,elem - 1,mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder,elem + 1, inEnd, mp);

  return root;
 }

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;
    map<int,int> mp;
    for(int i=inStart; i<=inEnd; i++)
        mp[inorder[i]] = i;
  
    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
