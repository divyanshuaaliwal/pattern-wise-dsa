// URL: https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            nums[i] = pow(nums[i], 2);
        }

        vector<int>ans(n);
        
        int start = 0;
        int end = n - 1;
        int index = n - 1;
        
        while(start <= end) {
            if(nums[start] <= nums[end]) {
                ans[index] = nums[end];
                index -= 1;
                end -= 1;
            }
            else {
                ans[index] = nums[start];
                index -= 1;
                start += 1;
            }
        }

        return ans;
    }
};
