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


Node *firstNode(Node *head)
{
    Node* slow = head,*fast = head;
        if(head == NULL) return NULL;
        
        // Basic Fast and Slow Method
        do {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        } while(fast && fast->next && fast != slow);
         
        // If Fast == NULL means No Cycle
        if(!fast || !fast->next) return NULL;
        fast = head;
        int c = 0;
        // Bring One Pointer TO Start, Start Travering One At A Time
        // Match-> Cycle Point
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
}
