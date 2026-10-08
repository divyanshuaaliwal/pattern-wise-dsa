// URL: https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int pos) {
        
        Node* nodeToDelete = NULL;
        
        if(pos == 1) {
            nodeToDelete = head;
            head = head->next;
            nodeToDelete->next = NULL;
            return head;
        }

        Node* temp = head;
        for(int i = 1 ; i < pos - 1 ; i++) {
            temp = temp->next;
        }
        
        nodeToDelete = temp->next;
        temp->next = temp->next->next;
        nodeToDelete->next = NULL;

        return head;
    }
};
