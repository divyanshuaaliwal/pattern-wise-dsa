// URL: https://leetcode.com/problems/longest-nice-subarray/

//     1      0 0 0 0 0 1
//     3      0 0 0 0 1 1 <-------
//     8      0 0 1 0 0 0         |--- OR: 1 1 1 0 1 1  (currMask)
//     48     1 1 0 0 0 0 <-------
//     10     0 0 1 0 1 0

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        int currMask = 0;
        int maxLen = 0;

        while(j < n) {

            while(i <= j && ((currMask & nums[j]) != 0)) {
                currMask ^= nums[i];
                i += 1;
            }

            currMask |= nums[j];

            maxLen = max(maxLen, j - i + 1);

            j += 1;
        }

        return maxLen;
    }
};
