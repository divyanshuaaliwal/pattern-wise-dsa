// URL: https://leetcode.com/problems/count-the-number-of-good-subarrays/

class Solution {
public:

    long long countAtMostK(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int currPairs = 0;
        unordered_map <int, int> mpp;
        long long totalSubarrays = 0;
        int n = nums.size();

        while(j < n) {

            mpp[nums[j]] += 1;
            currPairs += (mpp[nums[j]] - 1);

            while(i <= j && currPairs > k) {
                mpp[nums[i]] -= 1;
                currPairs -= mpp[nums[i]];
                i += 1;
            }

            if(i <= j && currPairs == k) {
                totalSubarrays += (j - i + 1);
            }

            if(i <= j && currPairs < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }   

    long long countGood(vector<int>& nums, int k) {

        long long n = nums.size();
        long long allSubarrays = (n * (n+1) / 2);
        
        return allSubarrays - countAtMostK(nums, k-1);
    }
};
