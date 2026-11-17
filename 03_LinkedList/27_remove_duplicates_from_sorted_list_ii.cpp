// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }

        ListNode* newHead = new ListNode(1e7);
        newHead->next = head;

        ListNode* prevNode = newHead;
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        ListNode* temp = newHead;

        while(nextNode) {

            int prevNodeValue = prevNode->val;
            int currNodeValue = currNode->val;
            int nextNodeValue = nextNode->val;

            if(prevNodeValue != currNodeValue && currNodeValue != nextNodeValue) {
                temp->next = currNode;
                temp = temp->next;
            }
            
            prevNode = prevNode->next;
            currNode = currNode->next;
            nextNode = nextNode->next;
        }
        
        temp->next = NULL;

        if(prevNode->val != currNode->val) {
            temp->next = currNode;
        }

        return newHead->next;
    }
};
