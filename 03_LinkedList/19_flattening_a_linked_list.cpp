// URL: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    
    Node* findMiddleNode(Node* head) {
        
        Node* slow = head;
        Node* fast = head->bottom;
       
        while(fast && fast->bottom) {
           slow = slow->bottom;
           fast = fast->bottom->bottom;
        }
        
        return slow;
    }
    
    Node* merge(Node* list1, Node* list2) {
    
        Node* head = new Node(-1);
        Node* temp = head;
    
        while(list1 && list2) {
    
            int list1Val = list1->data;
            int list2Val = list2->data;
    
            if(list1Val <= list2Val) {
                temp->bottom = list1;
                temp = temp->bottom;
                list1 = list1->bottom;
            }
            else {
                temp->bottom = list2;
                temp = temp->bottom;
                list2 = list2->bottom;
            }
        }
    
        if(list1) {
            temp->bottom = list1;
        }
    
        if(list2) {
            temp->bottom = list2;
        }
    
        return head->bottom;
    }
    
    Node* mergeSort(Node* head) {
        
        if(!head->bottom) {   // single Node
            return head;
        }
        
        Node* middleNode = findMiddleNode(head); 
        Node* head2 = middleNode->bottom;
        middleNode->bottom = NULL;
        
        Node* sortedLeftHalf = mergeSort(head);
        Node* sortedRightHalf = mergeSort(head2);
        
        return merge(sortedLeftHalf, sortedRightHalf);
    }
    
    
    Node* flatten(Node* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        Node* temp = head;
        while(temp) {
            Node* temp2 = temp;
            while(temp2->bottom) {
                temp2 = temp2->bottom;
            }
            temp2->bottom = temp->next;
            temp->next = NULL;
            temp = temp2->bottom;
        }
        
        return mergeSort(head);
    }
};
