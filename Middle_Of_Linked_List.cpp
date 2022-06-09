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

Node *findMiddle(Node *head) {
    // Write your code here
    if(head==NULL) return head;
    int length=0;
    Node *temp= head;
    while(temp){
        length++;
        temp=temp->next;
//         head=temp;
    }
    int mid= floor(length/2);
    temp=head;
    while(mid>0){
        temp=temp->next;
        mid--;
    }
    return temp;
        
}
