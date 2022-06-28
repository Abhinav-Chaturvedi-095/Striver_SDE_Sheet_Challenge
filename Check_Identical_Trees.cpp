/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

void Traversal(vector<int>& arr,BinaryTreeNode<int>* root){
    if(!root) {
        arr.push_back(-1);
        return;
    }
    Traversal(arr,root->left);
    Traversal(arr,root->right);
    arr.push_back(root->data);  
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    vector<int> tree1;
    vector<int> tree2;
    Traversal(tree1,root1);
    Traversal(tree2,root2);

   if(tree1.size()!=tree2.size()) return false;
    for(int i=0;i<tree1.size();i++)
        if(tree1[i]!=tree2[i]) return false; 
    return true;
}
