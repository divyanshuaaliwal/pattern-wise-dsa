// URL: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int closestSum = INT_MAX;
        int minDiff = INT_MAX;
        int n = nums.size();

        for(int firstIndex = 0 ; firstIndex < n ; firstIndex++) {
            if(firstIndex != 0 && nums[firstIndex] == nums[firstIndex - 1]) {
                continue;
            }
            int start = firstIndex + 1;
            int end = n - 1;
            while(start < end) {
                int sum = nums[firstIndex] + nums[start] + nums[end];
                if(sum == target) {
                    return sum;
                }
                else if(sum < target) {
                    int diff = abs(target - sum);
                    if(diff < minDiff) {
                        closestSum = sum;
                        minDiff = diff;
                    }
                    start += 1; 
                }
                else {
                    int diff = abs(target - sum);
                    if(diff < minDiff) {
                        closestSum = sum;
                        minDiff = diff;
                    }
                    end -= 1;
                }
            }
        }
        return closestSum;
    }
};
