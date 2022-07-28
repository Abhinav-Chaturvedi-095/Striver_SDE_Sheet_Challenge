#include <bits/stdc++.h>
class Queue {
    stack<int> st1;
    stack<int> st2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int x) {
        st1.push(x);
    }

    int deQueue() {
        if(!st2.empty()) {
            int t = st2.top();
            st2.pop();
            return t;
        }
        if(st1.empty()) return -1;
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int t = st2.top();
        st2.pop();
        return t;
    }

    int peek() {
        if(!st2.empty()) return st2.top();
        if(st1.empty()) return -1;
         while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    bool isEmpty() {
       if(st1.empty() && st2.empty()) return true;
        return false;
    }
};
