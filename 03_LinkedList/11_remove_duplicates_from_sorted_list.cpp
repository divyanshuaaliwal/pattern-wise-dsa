// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list

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

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast) {

            int slowVal = slow->val;
            int fastVal = fast->val;

            if(slowVal == fastVal) {
                fast = fast->next;
            }
            else {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }

        slow->next = NULL;

        return head;
    }
};
