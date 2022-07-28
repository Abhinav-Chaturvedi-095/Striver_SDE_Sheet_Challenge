#include <bits/stdc++.h>
class Stack {
    queue<int> q1;
    int ans = -1;

   public:
    Stack() {
       ans=-1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int x) {
        q1.push(x);
        int siz = q1.size()-1;
        while(siz--){
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        if(q1.size()) {
        ans= q1.front();
        q1.pop(); 
    }
        else ans = -1;
        return ans;
    }

    int top() {
        if(q1.empty()) return -1;
       return q1.front();
    }
};
