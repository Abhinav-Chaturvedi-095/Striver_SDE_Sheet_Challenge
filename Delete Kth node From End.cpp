#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(head==NULL || K==0) return head;
        LinkedListNode<int> * start = new LinkedListNode<int>(head->data);
        start -> next = head;
        LinkedListNode<int>* fast = start;
        LinkedListNode<int>* slow = start;  

        for(int i = 1; i <= K; ++i)
            fast = fast->next;
    
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
}
