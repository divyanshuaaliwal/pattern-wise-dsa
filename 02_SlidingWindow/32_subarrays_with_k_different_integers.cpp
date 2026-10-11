// URL: https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:

    int countAtMostK(vector<int>& nums, int k) {

        int i = 0;
        int j = 0;
        int totalSubarrays = 0;
        unordered_map <int, int> mpp;
        int n = nums.size();

        while(j < n) {
            
            mpp[nums[j]] += 1;

            while(i <= j && mpp.size() > k) {
                mpp[nums[i]] -= 1;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i += 1;
            }

            if(i <= j && mpp.size() == k) {
                totalSubarrays += (j - i + 1);
            }
                        
            if(i <= j && mpp.size() < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);      
    }
};
