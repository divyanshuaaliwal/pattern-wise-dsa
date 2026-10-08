// URL: https://leetcode.com/problems/reverse-linked-list/

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

    ListNode* reverseLL(ListNode* prevNode, ListNode* currNode) {
        
        if(!currNode) {
            return prevNode;
        }

        ListNode* nextNode = currNode->next;
        currNode->next = prevNode;
        return reverseLL(currNode, nextNode);
    }

    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) {
            return head;
        }

        return reverseLL(NULL, head);
    }
};
