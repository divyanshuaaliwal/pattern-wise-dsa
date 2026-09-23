// URL: https://www.geeksforgeeks.org/problems/segregate-even-and-odd-numbers4629/1

class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        
        int n = arr.size();
        int start = 0;
        int end = n - 1;
    
        while(start < end) {
            if(arr[start] % 2 == 0) {
                start++;
            }
            else if(arr[end] % 2 == 1) {
                end--;
            }
            else {
                swap(arr[start], arr[end]);
                start++;
                end--;
            } 
        }
        
        int firstOddElementIndex = 0;
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] & 1) {
                firstOddElementIndex = i;
                break;
            }
        }
        
        sort(arr.begin(), arr.begin() + firstOddElementIndex); 
        sort(arr.begin() + firstOddElementIndex, arr.end());  
    }
};
