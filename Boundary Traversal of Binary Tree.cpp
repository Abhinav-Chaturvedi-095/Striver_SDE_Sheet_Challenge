/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//root-left-leaf-right
bool isleaf(TreeNode<int>* root){
    if((!root->left)&&(!root->right))
        return true;
    return false;
}

void addleaves(TreeNode<int>* root,vector<int>& ans){
    if(isleaf(root)){
        ans.push_back(root->data);
        return ;
    }
    if(root->left) addleaves(root->left,ans);
    if(root->right) addleaves(root->right,ans);    
}

void addleft(TreeNode<int>* root,vector<int>& ans){
    TreeNode<int>* temp =root->left;
    while(temp){
        if(!isleaf(temp)) ans.push_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp=temp->right;
    }
}

void addright(TreeNode<int>* root,vector<int>& ans){
    TreeNode<int>* temp =root->right;
    vector<int> upside_down;
    while(temp){
        if(!isleaf(temp)) upside_down.push_back(temp->data);
        if(temp->right) temp = temp->right;
        else temp=temp->left;
    }
    for(int i=upside_down.size()-1;i>=0;i--)
        ans.push_back(upside_down[i]);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!isleaf(root)) ans.push_back(root->data);
    addleft(root,ans);
    addleaves(root,ans);
    addright(root,ans);
    
    return ans;
}
