// URL: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for(int firstIndex = 0; firstIndex < n ; firstIndex++) {
            if(firstIndex != 0 && nums[firstIndex] == nums[firstIndex - 1]) {
                continue;
            }
            int start = firstIndex + 1;
            int end = n - 1;
            while(start < end) {
                long sum = nums[firstIndex] + nums[start] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[firstIndex], nums[start], nums[end]});
                    start += 1;
                    end -= 1;
                    while(start < end && nums[start] == nums[start - 1]) {
                        start += 1;
                    }
                    while(start < end && nums[end] == nums[end + 1]) {
                        end -= 1;
                    }
                }
                else if (sum < 0) {
                    start += 1;
                }
                else {
                    end -= 1;
                }
            }
        }
        return ans;
    }
};
