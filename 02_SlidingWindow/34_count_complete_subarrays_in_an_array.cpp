// URL: https://leetcode.com/problems/count-complete-subarrays-in-an-array/

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

    int countCompleteSubarrays(vector<int>& nums) {

        set <int> sett (nums.begin(), nums.end());
        int k = sett.size();
        
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);      
    }
};
