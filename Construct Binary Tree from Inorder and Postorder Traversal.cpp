/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx, unordered_map<int, int>& mp) {
        if(inStart > inEnd) return nullptr;
        TreeNode<int>* root = new TreeNode<int>(post[postIdx--]);
        int inIdx = mp[root -> data];
        root -> right = build(in, post, inIdx+1, inEnd, postIdx,mp);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx,mp);
        return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
    unordered_map<int, int> mp;
    for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    int n = inorder.size(), postIdx = n-1;
    return build(inorder, postorder, 0, n-1, postIdx,mp);
}


    
