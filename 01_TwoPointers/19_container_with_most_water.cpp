// URL: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int start = 0;
        int end = n - 1;
        int maxWaterArea = 0;

        while(start < end) {

            int currWaterArea = min(height[start], height[end]) * (end - start);
            maxWaterArea = max(maxWaterArea, currWaterArea);

            if(height[start] < height[end]) {
                start += 1;
            }
            else {
                end -= 1;
            }
        }

        return maxWaterArea;
    }
};
