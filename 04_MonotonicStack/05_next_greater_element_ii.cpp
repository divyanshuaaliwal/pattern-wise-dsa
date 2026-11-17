// URL: https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
    
        int n = arr.size();
        stack <int> st; 
        vector <int> ans(n);
        
        for(int i = 2*n- 1 ; i >= 0 ; i--) {
        
            int element = arr[i % n];
        
            while(!st.empty() && st.top() <= element) {
                st.pop();
            }
        
            ans[i % n] = !st.empty() ? st.top() : -1;
            st.push(element);
        }
        
        return ans;
    }
};
