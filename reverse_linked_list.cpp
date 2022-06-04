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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    //iterative solution
    LinkedListNode<int> *nextNode,*prevNode=NULL;
    while(head!=NULL){
        nextNode = head->next;
        head->next=prevNode;
        prevNode=head;
        head=nextNode;    
    }
    return prevNode;
}
