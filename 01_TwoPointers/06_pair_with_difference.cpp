// URL: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        
        sort(arr.begin(), arr.end());
        
        int firstIndex = 0;
        int secondIndex = 1;
        int n = arr.size();
        
        while(secondIndex < n) {
            
            int diff = arr[secondIndex] - arr[firstIndex];
            
            if(diff == x) {
                return true;
            }
            else if(diff < x) {
                secondIndex += 1;
            }
            else {
                firstIndex += 1;
                if(firstIndex == secondIndex) {
                    secondIndex += 1;
                }
            }
        }
        
        return false;
    }
};
