// URL: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int firstIndex = 0 ; firstIndex < n ; firstIndex++) {
            if(firstIndex != 0 && nums[firstIndex] == nums[firstIndex - 1]) {
                continue;
            }
            for(int secondIndex = firstIndex + 1 ; secondIndex < n ; secondIndex++) {
                if(secondIndex != firstIndex + 1 && nums[secondIndex] == nums[secondIndex - 1]) {
                    continue;
                }
                int start = secondIndex + 1;
                int end = n - 1;
                while(start < end) {
                    long sum = nums[firstIndex];
                    sum += nums[secondIndex];
                    sum += nums[start];
                    sum += nums[end];
                    if(sum == target) {
                        ans.push_back({nums[firstIndex], nums[secondIndex], nums[start], nums[end]});
                        start += 1;
                        end -= 1;
                        while(start < end && nums[start] == nums[start - 1]) {
                            start += 1;
                        }
                        while(start < end && nums[end] == nums[end + 1]) {
                            end -= 1;
                        }
                    }
                    else if(sum < target) {
                        start += 1;
                    }
                    else {
                        end -= 1;
                    }
                }
            }
        }
        return ans;
    }
};
