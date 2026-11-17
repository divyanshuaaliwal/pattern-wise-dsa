// URL: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        
        if(!headRef || !headRef->next) {
            return headRef;
        }
        
        Node* head = headRef;
        Node* temp1 = head;
        Node* temp2 = head->next;
        
        while(temp2) {
            
            int temp1Val = temp1->data;
            int temp2Val = temp2->data;
            
            if(temp1Val == temp2Val) {
                temp2 = temp2->next;
            }
            else {
                temp1->next = temp2;
                temp2->prev = temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }
        
        temp1->next = NULL;
        return head;
    }
};
