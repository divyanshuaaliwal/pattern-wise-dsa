// URL: https://leetcode.com/problems/sort-list/

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
    
    ListNode* findMiddleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
       
        while(fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* list1,  ListNode* list2) {

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(list1 && list2) {

            int list1Val = list1->val;
            int list2Val = list2->val;

            if(list1Val <= list2Val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        if(list1) {
            temp->next = list1;
        }

        if(list2) {
            temp->next = list2;
        }

        return head->next;
    }
    
    ListNode* mergeSort(ListNode* head) {
        
        if(!head->next) {   // single Node
            return head;
        }
        
        ListNode* middleNode = findMiddleNode(head); 
        ListNode* head2 = middleNode->next;
        middleNode->next = NULL;
        
        ListNode* sortedLeftHalf = mergeSort(head);
        ListNode* sortedRightHalf = mergeSort(head2);
        
        return merge(sortedLeftHalf, sortedRightHalf);
    }

    ListNode* sortList(ListNode* head) {
        
        if(!head) {         // No Node
            return head;
        }
        
        return mergeSort(head);
    }
};
