// URL: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxLen = 0;
        unordered_map <int, int> mpp;
        
        while(j < n) {
        
            mpp[nums[j]] += 1;
            
            while(i <= j && mpp[nums[j]] > k) {
                mpp[nums[i]] -= 1;
                i += 1;
            }
            
            if(i <= j && mpp[nums[j]] == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            if(i <= j && mpp[nums[j]] < k) {
                maxLen = max(maxLen, j - i + 1);
            }
            
            j += 1; 
        }
        
        return maxLen;
    }
};
