// URL: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        int windowSize = k;
        
        unordered_map <int, int> mpp;
        long long maxSum = 0;
        long long currSum = 0;
        
        while(j < n) {

            mpp[nums[j]] += 1;
            currSum += nums[j];

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                if(mpp.size() == windowSize) {
                    maxSum = max(maxSum, currSum);
                }

                mpp[nums[i]] -= 1;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                
                currSum -= nums[i];
            
                i += 1;
                j += 1;
            }
        }
        
        return maxSum;        
    }
};
