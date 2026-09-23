// URL: https://www.geeksforgeeks.org/problems/perfect-arrays4645/1

class Solution {
  public:
    bool isPalindrome(vector<int> &arr) {

        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while(start <= end) {  
            if(arr[start] != arr[end]) {
                return false;
            }
            start += 1;
            end -= 1;
        }
        
        return true;
    }
};
