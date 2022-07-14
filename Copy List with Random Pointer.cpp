#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> hashmap;
    LinkedListNode<int>* temp = head;
    while(temp){
        LinkedListNode<int>* newNode = new LinkedListNode<int>(temp->data);
        hashmap[temp] = newNode;
        temp=temp->next;
    }
    LinkedListNode<int>* t=head;
    
    while(t != NULL) {
        LinkedListNode<int>* node = hashmap[t];
        node->next = (t->next != NULL) ? hashmap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashmap[t->random]:NULL;
        t = t->next;
    }
    return hashmap[head];
}
