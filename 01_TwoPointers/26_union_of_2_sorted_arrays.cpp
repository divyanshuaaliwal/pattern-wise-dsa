// URL: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
    
        int firstIndex = 0;
        int secondIndex = 0;    
        int n1 = a.size();
        int n2 = b.size();
        vector <int> ans;
        
        while(firstIndex < n1 && secondIndex < n2) {
            if(a[firstIndex] < b[secondIndex]) {
                if(ans.empty() || ans.back() != a[firstIndex]) {
                    ans.push_back(a[firstIndex]);
                }
                firstIndex += 1;
            }
            else {
                if(ans.empty() || ans.back() != b[secondIndex]) {
                    ans.push_back(b[secondIndex]);
                }
                secondIndex += 1;
            }
        }
        
        while(firstIndex < n1) {
            if(ans.back() != a[firstIndex]) {
                ans.push_back(a[firstIndex]);
            }
            firstIndex += 1;
        }
        
    
        while(secondIndex < n2) {
            if(ans.back() != b[secondIndex]) {
                ans.push_back(b[secondIndex]);
            }
            secondIndex += 1;
        }
        
        return ans;
        
    }
};
