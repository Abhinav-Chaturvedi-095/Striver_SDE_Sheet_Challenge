#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    
    // using slow and fast pointer
    
    if(head == NULL) 
        return false;
    
    Node* fast = head;
    Node* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow) 
            return true;
    }
    return false;
}
