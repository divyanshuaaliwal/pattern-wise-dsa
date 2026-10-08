// URL: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1

/* Linked List Node Structure
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        
        int n = arr.size();
        
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i = 1 ; i < n ; i++) {
            int element = arr[i];
            temp->next = new Node(element);
            temp = temp->next;
        }
        
        return head;
    }
};
