#include <bits/stdc++.h>
void sortS(vector<int> &ans, stack<int> &stack) {
    if(stack.empty()) {
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return;
    }
    ans.push_back(stack.top());
    stack.pop();
    sortS(ans, stack);
    stack.push(ans.back());
    ans.pop_back();
}
void sortStack(stack<int> &stack)
{
    vector<int> ans;
    sortS(ans, stack);
}
