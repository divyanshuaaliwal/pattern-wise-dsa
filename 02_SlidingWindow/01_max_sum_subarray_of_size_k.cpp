// URL: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int i = 0;
        int j = 0;
        int n = arr.size();
        int currSum = 0;
        int maxSum = INT_MIN;
        
        while(j < n) {
            
            currSum += arr[j];
            
            if(j-i+1 < k) {
                j += 1;
            }
            else {
                maxSum = max(maxSum, currSum);
                currSum -= arr[i];
                i += 1;
                j += 1;
            }
        }
        
        return maxSum;  
    }
};
