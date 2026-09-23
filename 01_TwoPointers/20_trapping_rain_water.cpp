// URL: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int start = 0;
        int startMaxVal = height[0];
        int end = n - 1;
        int endMaxVal = height[n - 1];
        int totalWater = 0;

        while(start <= end) {
            if(startMaxVal < endMaxVal) {
                startMaxVal = max(startMaxVal, height[start]);
                totalWater += (startMaxVal - height[start]);
                start += 1;
            }
            else {
                endMaxVal = max(endMaxVal, height[end]);
                totalWater += (endMaxVal - height[end]);
                end -= 1;
            }
        }

        return totalWater;
    }
};
