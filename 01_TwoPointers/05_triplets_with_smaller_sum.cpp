// URL: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

class Solution {
  public:
    int countTriplets(int target, vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int totalTriplets = 0;
        
        for(int firstIndex = 0 ; firstIndex < n ; firstIndex++) {
            int start = firstIndex + 1;
            int end = n - 1;
            while(start < end) {
                long sum = arr[firstIndex] + arr[start] + arr[end];
                if(sum == target) {
                    end -= 1;
                }
                else if(sum < target) {
                    totalTriplets += (end - start);
                    start += 1;
                }
                else {
                    end -= 1;
                }
            }
        }
        return totalTriplets;
    }
};
