// URL: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int left = 0;
        int maxCount = 0;
        long long count = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == maxElement) {
                maxCount += 1;
            }

            while(maxCount >= k) {
                if(nums[left] == maxElement) {
                    maxCount -= 1;
                }
                left += 1;
            }

            count += left;
        }

        return count;
    }
};