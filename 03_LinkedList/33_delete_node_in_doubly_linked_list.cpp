// URL: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

/* Structure of Doubly Linked List Node
class Node {
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int val) {
		data = val;
		this->next = this->prev = nullptr;
	}
};*/

class Solution {
  public:
    Node* delPos(Node* head, int k) {
        
        if(k == 1) {
            Node* temp = head->next;
            head->next = NULL;
            if(temp) {
                temp->prev = NULL;
            }
            return temp;
        }

        Node* temp = head;
        for(int i = 1 ; i < k-1 ; i++) {
            temp = temp->next;
        }
        
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if(delNode->next) {
            delNode->next->prev = temp;
        }
        
        delNode->next = NULL;
        delNode->prev = NULL;
        delete delNode;
        
        return head;
    }
};
