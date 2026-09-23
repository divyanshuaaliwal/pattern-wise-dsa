// URL: https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int firstIndex = 0;
        int secondIndex = 0;

        while(secondIndex < n) {
            if(nums[secondIndex] != 0) {
                swap(nums[firstIndex], nums[secondIndex]);
                firstIndex += 1;
                secondIndex += 1;
            }
            else {
                secondIndex += 1;
            }
        }
    }
};