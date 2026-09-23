// URL: https://leetcode.com/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector <int> ans (n, -1);
        int windowSize = 2 * k + 1;
        long currSum = 0;
        
        while(j < n) {

            currSum += nums[j];

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                ans[j - k] = currSum / windowSize;
                currSum -= nums[i];
                i += 1;
                j += 1;
            }
        }

        return ans;
    }
};
