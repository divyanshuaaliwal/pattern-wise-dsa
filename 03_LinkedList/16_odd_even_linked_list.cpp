// URL: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTemp = head;
        ListNode* evenTemp = head->next;

        while(evenTemp && evenTemp->next) {
            oddTemp->next = oddTemp->next->next;
            evenTemp->next = evenTemp->next->next;
            oddTemp = oddTemp->next;
            evenTemp = evenTemp->next;
        }

        oddTemp->next = evenHead;

        return oddHead;
    }
};
