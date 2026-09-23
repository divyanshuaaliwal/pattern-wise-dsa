// URL: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        
        while(start < end) {
            
            if(arr[start] == 0) {
                start += 1;
            }
            else if(arr[end] == 1) {
                end -= 1; 
            }
            else {
                swap(arr[start], arr[end]);
                start += 1;
                end -= 1;
            }
        }
    }
};
