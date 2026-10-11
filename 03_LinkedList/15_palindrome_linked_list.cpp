// URL: https://leetcode.com/problems/palindrome-linked-list/

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

    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = slow->next;
        slow->next = NULL;

        ListNode* head2 = reverseLL(NULL, secondHalfHead);

        while(head && head2) {
            if(head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};
