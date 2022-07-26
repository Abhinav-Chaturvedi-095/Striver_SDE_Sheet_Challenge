#include <bits/stdc++.h> 
/********************************
    Following is the class structure of the Node class:
    
    class Node
    {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
    };
********************************/


Node *rotate(Node *head, int k) {
     int n = 0;
        Node* p = head;
        while(p) {
            p = p->next;
            n++;
        }
        if(n == 0) return head;
        k %= n;
        if(k == 0) return head;
        n = n - k;
        p = head;
        n--;
        while(n-- > 0) p = p->next;
        Node* newHead = p->next;
        p->next = NULL;
        p = newHead;
        while(p->next) p = p->next;
        p->next = head;
        return newHead;
}
