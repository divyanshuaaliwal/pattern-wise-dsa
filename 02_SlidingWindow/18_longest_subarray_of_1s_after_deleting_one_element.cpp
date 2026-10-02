// URL: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int k = 1;

        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxLen = 0;
        int currZeros = 0;

        while(j < n) {

            if(nums[j] == 0) {
                currZeros += 1;
            }

            while(i <= j && currZeros > k) {
                if(nums[i] == 0) {
                    currZeros -= 1;
                }
                i += 1;
            }

            if(i <= j && currZeros == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            if(i <= j && currZeros < k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j += 1;
        }

        return maxLen - 1;
    }
};
