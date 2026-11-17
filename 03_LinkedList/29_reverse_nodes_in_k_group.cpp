// URL: https://leetcode.com/problems/reverse-nodes-in-k-group/

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

    ListNode* reverseLL(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        
        while(currNode) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        for(int i = 1 ; i < k ; i++) {
            if(temp) {
                temp = temp->next;
            }
        }

        if(!temp) {
            return head;
        }

        ListNode* tempNext = temp->next;
        temp->next = NULL;

        reverseLL(head);

        head->next = reverseKGroup(tempNext, k);
        return temp;
    }
};
