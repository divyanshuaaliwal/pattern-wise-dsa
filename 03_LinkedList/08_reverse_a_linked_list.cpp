// URL: https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        Node* prevNode = NULL;
        Node* currNode = head;
        
        while(currNode) {
            Node* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
        
    }
};
