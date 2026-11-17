// URL: https://www.geeksforgeeks.org/problems/previous-smaller-element/1

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        
        int n = arr.size();
        stack <int> st; 
        vector <int> ans(n);

        for(int i = 0 ; i < n ; i++) {

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
