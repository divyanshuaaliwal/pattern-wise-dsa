// URL: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* temp) {
        
        int count = 0;
        
        while(temp) {
            count += 1;
            temp = temp->next;
        }
        
        return count;
        
    }
};