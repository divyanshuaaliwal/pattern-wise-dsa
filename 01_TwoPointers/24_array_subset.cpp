// URL: https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

class Solution {
  public:

    bool isSubset(vector<int> &a, vector<int> &b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int firstIndex = 0;
        int secondIndex = 0;
        int n1 = a.size();
        int n2 = b.size();
        
        while(firstIndex < n1 && secondIndex < n2) {
            if(a[firstIndex] == b[secondIndex]) {
                firstIndex += 1;
                secondIndex += 1;
            }
            else {
                firstIndex += 1;
            }
        }
        
        return secondIndex == n2;
    }
};
