// URL: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int zeroIndex = 0;
        int onesIndex = 0;
        int twosIndex = n-1;

        while(onesIndex <= twosIndex) {
            if(nums[onesIndex] == 0) {
                swap(nums[onesIndex], nums[zeroIndex]);
                zeroIndex += 1;
                onesIndex += 1;
            }
            else if(nums[onesIndex] == 1) {
                onesIndex += 1;
            }
            else {
                swap(nums[onesIndex], nums[twosIndex]);
                twosIndex -= 1;
            }
        }
    }
};
