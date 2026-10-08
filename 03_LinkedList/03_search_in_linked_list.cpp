// URL: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        
        Node* temp = head;
        
        while(temp) {
            if(temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        
        return false;
    }
};
