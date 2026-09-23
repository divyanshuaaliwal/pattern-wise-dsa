// URL: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        
        int n1 = a.size();
        int n2 = b.size();
        int firstIndex = n1 - 1;
        int secondIndex = 0;
        
        while(firstIndex >= 0 && secondIndex <= n2 - 1 && a[firstIndex] > b[secondIndex]) {
            swap(a[firstIndex], b[secondIndex]);
            firstIndex -= 1;
            secondIndex += 1;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
    }
};
