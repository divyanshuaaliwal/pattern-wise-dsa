// URL: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int i = 0;
        int j = 0;
        int n = cardPoints.size();
        int windowSize = n - k;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int currSum = 0;
        int minSum = INT_MAX;

        if(windowSize == 0) {
            return totalSum;
        }

        while(j < n) {
            
            currSum += cardPoints[j];

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                minSum = min(minSum, currSum);
                currSum -= cardPoints[i];
                i += 1;
                j += 1;
            }
        }

        return totalSum - minSum;
    }
};
