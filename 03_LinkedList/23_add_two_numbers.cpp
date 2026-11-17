// URL: https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;

        while(l1 || l2) {

            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;

            int sum = l1Val + l2Val + carry;
            int lastDigit = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(lastDigit);
            temp = temp->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        if(carry) {
            temp->next = new ListNode(carry);
        }

        return head->next;
    }
};
