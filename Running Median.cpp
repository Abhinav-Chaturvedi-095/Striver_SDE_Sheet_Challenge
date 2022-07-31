#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        if(!maxi.size() || num < maxi.top()) {
            maxi.push(num);
        } else mini.push(num);
        
        if(maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        } else if(mini.size() > maxi.size() + 1) {
            maxi.push(mini.top());
            mini.pop();
        }
        if(maxi.size() == mini.size()) {
            cout << ((maxi.top() + mini.top()) / 2) << " ";
        } else {
            if(maxi.size() > mini.size()) cout << maxi.top() << " ";
            else cout << mini.top() << " ";
        }
    }
    cout << endl;
}
