// URL: https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* tail = head;
        ListNode* temp = head->next;
        int sum = 0;

        while(temp) {    
            if(temp->val == 0) {
                tail->next->val = sum;
                tail = tail->next;
                sum = 0;
                temp = temp->next;
            }
            else {
                sum += temp->val;
                temp = temp->next;
            }
        }

        tail->next = NULL;
        return head->next;
    }
};
