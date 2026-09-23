// URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int start = 0;
        int end = n - 1;

        while(start < end) {

            long sum = numbers[start] + numbers[end];

            if(sum == target) {
                return {start + 1, end + 1};
            } 
            else if(sum < target) {
                start += 1;
            }
            else {
                end -= 1;
            }
        }   

        return {-1, -1};
    }
};
