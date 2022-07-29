/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int,int> m; 
      
        queue<pair<BinaryTreeNode<int>*, int>> q; // Element and corresp. height
        vector<int> res;
        if(!root) return res;
        q.push({root, 0}); 
        while(!q.empty()){
            BinaryTreeNode<int>* curr = q.front().first;
            int currht = q.front().second;
            q.pop();
            m[currht] = curr->data; // if val for this currht already exists, continue
            if(curr->left) q.push({curr->left, currht-1});
            if(curr->right) q.push({curr->right, currht+1});
        }
        // our map m has all the elements visible from top at each vertical level
        for(auto t: m){
            res.push_back(t.second);
        }
        return res;
}
