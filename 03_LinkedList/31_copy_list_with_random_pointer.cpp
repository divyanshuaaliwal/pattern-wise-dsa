// URL: https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void addNewNodes(Node* temp) {
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPointers(Node* temp) {
        while(temp) {
            Node* randomPtr = temp->random;
            temp->next->random = (randomPtr ? randomPtr->next : NULL); 
            temp = temp->next->next;
        }
    }
    
    Node* removeNewNodes(Node* temp) {
        Node* head2 = temp->next;
        Node* temp1 = temp;
        Node* temp2 = temp->next;
       
        while(temp2->next) {
            temp1->next = temp1->next->next;
            temp2->next = temp2->next->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1->next = NULL;
        return head2;
    }

    Node* copyRandomList(Node* head) {

        if(!head) {
            return head;
        }

        addNewNodes(head);
        connectRandomPointers(head);
        return removeNewNodes(head);
    }
};
