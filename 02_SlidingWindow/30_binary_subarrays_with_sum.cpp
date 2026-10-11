// URL: https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:

    int countAtMostK(vector<int>& nums, int goal) {

        int i = 0;
        int j = 0;
        int currSum = 0;
        int totalSubarrays = 0;
        int n = nums.size();

        while(j < n) {
            
            currSum += nums[j];

            while(i <= j && currSum > goal) {
                currSum -= nums[i];
                i += 1;
            }

            if(i <= j && currSum == goal) {
                totalSubarrays += (j - i + 1);
            }
                        
            if(i <= j && currSum < goal) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMostK(nums, goal) - countAtMostK(nums, goal - 1); 
    }
};
