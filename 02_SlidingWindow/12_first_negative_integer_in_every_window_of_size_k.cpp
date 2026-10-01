// URL: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
    
        int i = 0;
        int j = 0;
        int n = arr.size();
        int windowSize = k;
        queue <int> q;
        vector <int> ans;
        
        while(j < n) {
            
            if(arr[j] < 0) {
                q.push(j);
            }
            
            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                int element = !q.empty() ? arr[q.front()] : 0;
                ans.push_back(element);
                
                if(!q.empty() && q.front() == i) {
                    q.pop();
                }
                
                i += 1;
                j += 1;
            }
        }
        
        return ans;
    }
};
