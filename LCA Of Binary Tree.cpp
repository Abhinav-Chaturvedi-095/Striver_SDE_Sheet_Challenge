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
bool findPath(TreeNode<int> *root,int k,vector<int>&path){
    if(root==NULL)
        return false;
    path.push_back(root->data);
    if(root->data==k)
        return true;
    if((root->left && findPath(root->left,k,path)) || (root->right && findPath(root->right,k,path)))
        return true;
    path.pop_back();
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    vector<int> p1;
    vector<int> p2;
    
    if(!findPath(root,x,p1) || !findPath(root,y,p2))
        return -1;    
    int i;
    for( i=0; i< p1.size() && i< p2.size();i++)
        if(p1[i]!=p2[i])
            break;
    return p1[i-1];
    
}
