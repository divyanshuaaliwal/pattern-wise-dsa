// URL: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:

    int countAtMostK(vector<int>& nums, int k) {

        int i = 0;
        int j = 0;
        int currOddNums = 0;
        int totalSubarrays = 0;
        int n = nums.size();

        while(j < n) {
            
            currOddNums += (nums[j] & 1);

            while(i <= j && currOddNums > k) {
                currOddNums -= (nums[i] & 1);
                i += 1;
            }

            if(i <= j && currOddNums == k) {
                totalSubarrays += (j - i + 1);
            }
                        
            if(i <= j && currOddNums < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1); 
    }
};