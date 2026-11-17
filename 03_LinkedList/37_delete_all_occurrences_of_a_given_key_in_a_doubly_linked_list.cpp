// URL: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int k) {
        
        Node* newHead = new Node(-1);
        newHead->next = head;
    
        Node* temp1 = newHead;
        Node* temp2 = head;
    
    
        while(temp2) {
            if(temp2->data == k) {
                temp2 = temp2->next;
            }
            else {
                
                if(temp2->prev) {
                    temp2->prev->next = NULL;
                }
                
                temp1->next = temp2;
                temp2->prev = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    
        temp1->next = NULL;
        return newHead->next;
    }
};
