// URL: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int firstIndex = 0;
        int secondIndex = n - 1;

        while(firstIndex + 1 < n && nums[firstIndex] <= nums[firstIndex + 1]) {
            firstIndex += 1;
        }

        while(secondIndex - 1 >= 0 && nums[secondIndex - 1] <= nums[secondIndex]) {
            secondIndex -= 1;
        }

        if(firstIndex == n - 1) {
            return 0;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int index = firstIndex; 
        while(index <= secondIndex) {
            mini = min(mini, nums[index]);
            maxi = max(maxi, nums[index]);
            index += 1;
        }

        while(firstIndex >= 0 && nums[firstIndex] > mini) {
            firstIndex -= 1;
        }

        while(secondIndex < n && nums[secondIndex] < maxi) {
            secondIndex += 1;
        }

        return secondIndex - firstIndex - 1;
    }
};
