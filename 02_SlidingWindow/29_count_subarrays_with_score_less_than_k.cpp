// URL: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long currSum = 0;
        long long totalSubarrays = 0;

        while(j < n) {

            currSum += nums[j];

            while(i <= j && currSum * (j - i + 1) > k) {
                currSum -= nums[i];
                i += 1;
            }

            while(i <= j && currSum * (j - i + 1) == k) {
                currSum -= nums[i];
                i += 1;
            }

            if(i <= j && currSum * (j - i + 1) < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }
};
