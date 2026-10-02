// URL: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        int minLen = INT_MAX;
        int currSum = 0;

        while(j < n) {

            currSum += nums[j];

            while(i <= j && currSum > target) {        // greater than
                minLen = min(minLen, j - i + 1);
                currSum -= nums[i];
                i += 1;
            } 

            while(i <= j && currSum == target) {        // equals to
                minLen = min(minLen, j - i + 1);
                currSum -= nums[i];
                i += 1;
            } 

            j += 1;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
