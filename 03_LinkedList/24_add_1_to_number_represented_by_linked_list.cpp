// URL: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/* Structure of linked list Node
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
    
    int recursive(Node* temp) {
        
        if(!temp) {
            return 1;
        } 
        
        int sum = temp->data + recursive(temp->next);
        int lastDigit = sum % 10;
        int carry = sum / 10;
        
        temp->data = lastDigit;
        
        return carry;
    }
  
    Node* addOne(Node* head) {
        
        int carry = recursive(head);
        
        if(carry) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
