// URL: https://leetcode.com/problems/rotate-list/

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

    void findTailAndLength(ListNode* &tail, int &length) {
        while(tail->next) {
            length += 1;
            tail = tail->next;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next || k == 0) {
            return head;
        }

        ListNode* tail = head;
        int length = 1;
        findTailAndLength(tail, length);

        k = k % length;

        if(k == 0) {
            return head;
        }
 
        int n = length - k; 
        ListNode* temp = head;        
        for(int i = 1 ; i < n ; i++) {
            temp = temp->next;
        }
        
        ListNode* tempNext = temp->next;
        temp->next = NULL;
        tail->next = head;
        return tempNext;
    }   
};