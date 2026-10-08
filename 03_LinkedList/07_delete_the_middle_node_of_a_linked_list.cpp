// URL: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        nodeToDelete->next = NULL;

        return head;
    }
};
