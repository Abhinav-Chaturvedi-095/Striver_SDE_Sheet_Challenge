#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;
    vector<int> ans;
    int res[n];
    for(int i=n-1;i>=0;i--){
        if(!s.empty()){
            while (!s.empty() && s.top() <= arr[i])
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
        
    for (int i=0;i<n;i++) 
        ans.push_back(res[i]);
    
    return ans;
}
