// URL: https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class Solution {
  public:
    void linkDelete(Node* head, int n, int m) {
        
        Node* temp1 = head;
        
        while(temp1) {
            
            for(int i = 1 ; i < m && temp1; i++) {
                temp1 = temp1->next;
            }
            
            if(!temp1) {
                break;
            }
            
            Node* temp2 = temp1->next;
            
            for(int i = 1 ; i < n && temp2 ; i++) {
                temp2 = temp2->next;
            }
            
            temp1->next = temp2 ? temp2->next : NULL;
            temp1 = temp1->next;
        }
    }
};
