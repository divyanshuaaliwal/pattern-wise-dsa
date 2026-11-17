// URL: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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

    bool isCriticalPoint(int prevNodeValue, int currNodeValue, int nextNodeValue) {
        if(prevNodeValue < currNodeValue && nextNodeValue < currNodeValue) {
            return true;
        }
        else if (prevNodeValue > currNodeValue && nextNodeValue > currNodeValue) {
            return true;
        }
        else {
            return false;
        }
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // no node   single node    double nodes        triple nodes
        if(!head || !head->next || !head->next->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCriticalPoint = -1;
        int secondCriticalPoint = -1;
        int thirdCriticalPoint = -1;

        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        ListNode* nextNode = head->next->next;

        int count = 1;
        int minima = INT_MAX;
        int maxima = 0;

        while(nextNode) {

            bool isCurrNodeACriticalPoint = isCriticalPoint(prevNode->val, currNode->val, nextNode->val);

            if(isCurrNodeACriticalPoint) {
                if(firstCriticalPoint == -1) {
                    firstCriticalPoint = count;
                }
                else if(secondCriticalPoint == -1) {
                    secondCriticalPoint = count;
                    minima = min(minima, secondCriticalPoint - firstCriticalPoint);
                }
                else if(thirdCriticalPoint == -1) {
                    thirdCriticalPoint = count;
                    minima = min(minima, thirdCriticalPoint - secondCriticalPoint);
                }
                else {
                    secondCriticalPoint = thirdCriticalPoint;
                    thirdCriticalPoint = count;
                    minima = min(minima, thirdCriticalPoint - secondCriticalPoint);
                }
            }
            
            prevNode = prevNode->next;
            currNode = currNode->next;
            nextNode = nextNode->next;
            count += 1;
        }
        
        if(firstCriticalPoint == -1 || secondCriticalPoint == -1) {
            return {-1, -1};
        }

        if(thirdCriticalPoint == -1) {
            return {minima, minima};
        }

        maxima = thirdCriticalPoint - firstCriticalPoint;
        return {minima, maxima};
    }
};
