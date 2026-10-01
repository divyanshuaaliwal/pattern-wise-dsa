// URL: https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        int i = 0;
        int j = 0;
        int n = arr.size();
        int windowSize = k;
        deque <int> dq;
        vector <int> ans;
        
        while(j < n) {
            
            while(!dq.empty() && arr[dq.back()] <= arr[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                int element = arr[dq.front()];
                ans.push_back(element);
                
                if(dq.front() == i) {
                    dq.pop_front();
                }
                
                i += 1;
                j += 1;
            }
        }
        
        return ans;
    }
};
