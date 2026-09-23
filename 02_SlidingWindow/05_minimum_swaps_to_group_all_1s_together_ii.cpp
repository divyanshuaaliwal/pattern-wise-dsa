// URL: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int size = nums.size();
        int n = 2 * size;
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int windowSize = totalOnes;
        int currOnes = 0;
        int miniOnesRequired = INT_MAX;

        while(j < n) {

            currOnes += nums[j % size];

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                int totalOnesNeeded = windowSize - currOnes;
                miniOnesRequired = min(miniOnesRequired, totalOnesNeeded);
                currOnes -= nums[i % size];
                i += 1;
                j += 1;
            }
        }

        return miniOnesRequired;
    }
};
