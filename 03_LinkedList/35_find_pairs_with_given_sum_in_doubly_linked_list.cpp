// URL: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
  
     Node* getTail(Node* temp) {
        while(temp->next) {
            temp = temp->next;
        }
        return temp;
    }
    
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        
        vector<vector<int>>ans;
        
        Node* start = head;
        Node* end = getTail(head);

        while(start != end && end->next != start) {

            int value = start->data + end->data;

            if(value == target) {
                ans.push_back({start->data, end->data});
                start = start->next;
                end = end->prev;
            }
            else if (value < target) {
                start = start->next;
            }
            else {
                end = end->prev;                
            }
        }

        return ans;
        
    }
};
