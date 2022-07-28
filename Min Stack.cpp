// Implement class for minStack.
#include <bits/stdc++.h>
class minStack
{
    // Write your code here.
    
    public:
    
    class Node {
        
        public :
        int data;
        Node* next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    stack<int> st;
    Node* root;
    minStack() {
        root = NULL;
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        if(root == NULL) {
            root = temp;
        } else {
            if(root->data >= temp->data) {
                temp->next = root;
                root = temp;
            }
        }
        st.push(val);
    }
    
    int pop() {
        if(st.empty()) return -1;
        if(root->data == st.top()) {
            root = root->next;
        }
        int t = st.top();
        st.pop();
        return t;
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();   
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return root->data;
    }
};
