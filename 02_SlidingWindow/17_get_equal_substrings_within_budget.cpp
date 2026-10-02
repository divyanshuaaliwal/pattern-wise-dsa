// URL: https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        int currCost = 0;

        while(j < n) {

            currCost += abs(s[j] - t[j]);

            while(i <= j && currCost > maxCost) {       // greater than
                currCost -= abs(s[i] - t[i]);
                i += 1;
            } 

            if(i <= j && currCost == maxCost) {         // equals to
                maxLen = max(maxLen, j-i+1);
            }

            if(i <= j && currCost < maxCost) {          // lesser than
                maxLen = max(maxLen, j-i+1);
            }

            j += 1;                                    
        }

        return maxLen;
    }
};
