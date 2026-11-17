// URL: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
  
    Node* usingIterative(Node* head) {
        
        Node* prevNode = NULL;
        Node* currNode = head;
        while(currNode) {
            Node* nextNode = currNode->next;
            currNode->next = prevNode;
            currNode->prev = nextNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
    }
    
    
    Node* usingRecursive(Node* prevNode, Node* currNode) {
        
        if(!currNode) {
            return prevNode;
        }
        
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        return usingRecursive(currNode, nextNode);
    }

    Node *reverse(Node* head) {
        
        // return usingIterative(head);
        return usingRecursive(NULL, head);
    }
};
