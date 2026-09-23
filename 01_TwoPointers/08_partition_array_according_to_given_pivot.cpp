// URL: https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        int smallerCount = 0;
        int equalCount = 0;
        int greaterCount = 0;
    
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] < pivot) {
                smallerCount += 1;
            }
            else if(nums[i] == pivot) {
                equalCount += 1;
            }
            else {
                greaterCount += 1;
            }
        }

        int smallerIndex = 0;
        int equalIndex = smallerCount;
        int greaterIndex = smallerCount + equalCount; 

        vector<int>ans(n);
        
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] < pivot) {
                ans[smallerIndex] = nums[i];
                smallerIndex += 1;
            }
            else if(nums[i] == pivot) {
                ans[equalIndex] = nums[i];
                equalIndex += 1;
            }
            else {
                ans[greaterIndex] = nums[i];
                greaterIndex += 1;
            }
        }

        return ans;
    }
};
