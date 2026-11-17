// URL: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
    
        int n = arr.size();
        stack <int> st; 
        vector <int> ans(n);
        
        for(int i = n - 1 ; i >= 0 ; i--) {
        
            int element = arr[i];
        
            while(!st.empty() && st.top() <= element) {
                st.pop();
            }
        
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(element);
        }
        
        return ans;
    }
};
