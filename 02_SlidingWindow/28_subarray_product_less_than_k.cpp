// URL: https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        int currProduct = 1;
        int totalSubarrays = 0;

        while(j < n) {

            currProduct *= nums[j];

            while(i <= j && currProduct > k) {
                currProduct /= nums[i];
                i += 1;
            }

            while(i <= j && currProduct == k) {
                currProduct /= nums[i];
                i += 1;
            }
            
            if(i <= j && currProduct < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }
    
        return totalSubarrays;
    }
};
