// URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head || n == 0) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 1 ; i <= n ; i++) {
            fast = fast->next;
        }

        if(!fast) {
            ListNode* nodeToRemove = head;
            head = head->next;
            nodeToRemove->next = NULL;
            return head;
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;
        nodeToRemove->next = NULL;

        return head;
    }
};
