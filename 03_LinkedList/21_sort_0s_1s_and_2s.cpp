// URL: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zeroTemp = zeroHead;
        Node* oneTemp = oneHead;
        Node* twoTemp = twoHead;
        
        Node* temp = head;
        
        while(temp) {
            
            int tempVal = temp->data;
            
            if(tempVal == 0) {
                zeroTemp->next = temp;
                zeroTemp = zeroTemp->next;
            }
            else if(tempVal == 1) {
                oneTemp->next = temp;
                oneTemp = oneTemp->next;
            }
            else {
                twoTemp->next = temp;
                twoTemp = twoTemp->next;
            }
            
            temp = temp->next;
        }
        
        twoTemp->next = NULL;
        
        zeroTemp->next = oneHead->next ? oneHead->next : twoHead->next;
        oneTemp->next = twoHead->next;
        
        if(zeroHead->next) {
           return zeroHead->next;
        }
        else if(oneHead->next) {
           return oneHead->next;
        }
        else {
           return twoHead->next;
        }
    }
};
