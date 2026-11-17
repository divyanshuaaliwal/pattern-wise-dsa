// URL: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        
        Node* temp = head;
        for(int i = 0 ; i < p ; i++) {
            temp = temp->next;
        }
        
        Node* newNode = new Node(x);
        newNode->next = temp->next;
        if(temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        
        return head;
    }
};
