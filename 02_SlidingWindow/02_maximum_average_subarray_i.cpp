// URL: https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
                
        int i = 0;
        int j = 0;
        int n = nums.size();
        double currSum = 0;
        double maxAvg = INT_MIN;
        
        while(j < n) {
            
            currSum += nums[j];
            
            if(j-i+1 < k) {
                j += 1;
            }
            else {
                double currAvg = currSum / k;
                maxAvg = max(maxAvg, currAvg);
                currSum -= nums[i];
                i += 1;
                j += 1;
            }
        }
        
        return maxAvg;
    }
};