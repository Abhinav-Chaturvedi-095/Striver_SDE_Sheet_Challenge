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
#include <bits/stdc++.h> 

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head == NULL) return head;
        
        // Calculate Length Of Linked List
        int c = 0;
        Node *p = head;
        while(p) {
            p = p->next;
            c++;
        }
        
        // Dummy Node For Head Pointer
        Node* dummy = new Node(0);
        dummy->next = head;
        int k = 0;
        Node *curr = dummy,*nex = dummy, *prev = dummy;
        
        while(c > 0 && k < n) {
            if(b[k] == 0) {
                k++;
                continue;
            }
            // Pointing To First Element OF New Set
            curr = prev->next;
            nex = curr->next;
            for(int i = 1; i < min(b[k],c); i++) {
                
                // Pointing To Next to Next Element
                curr->next = nex->next;
                
                // Reversing The Pointer
                nex->next = prev->next;
                
                // Making Previous Point To Next
                // In The First Go, it is making The Head Node Points To 
                prev->next = nex;
                
                // Next Point TO Next Of Current
                nex = curr->next;
            }
            
            // Making Previous Current
            prev = curr;
            c -= b[k];
            k++;
        }
        return dummy->next;
}
