// URL: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        int windowSize = k;
        deque <int> dq;
        vector <int> ans;

        while(j < n) {

            if(!dq.empty() && dq.back() + 1 != nums[j]) {
                dq.clear();               
            }

            dq.push_back(nums[j]);

            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {

                int element = (dq.size() == windowSize) ? dq.back() : -1;
                ans.push_back(element);

                if(dq.size() == windowSize) {
                    dq.pop_front();
                }

                i += 1;
                j += 1;
            }
        }
        return ans;
    }
};
