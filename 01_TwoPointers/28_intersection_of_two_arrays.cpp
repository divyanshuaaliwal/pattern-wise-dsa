// URL: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int firstIndex = 0;
        int secondIndex = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector <int> ans;

        while(firstIndex < n1 && secondIndex < n2) {
            if(nums1[firstIndex] == nums2[secondIndex]) {
                if(ans.empty() || ans.back() != nums1[firstIndex]) {
                    ans.push_back(nums1[firstIndex]);
                }
                firstIndex += 1;
                secondIndex += 1;
            }
            else if(nums1[firstIndex] < nums2[secondIndex]) {
                firstIndex += 1;
            }
            else {
                secondIndex += 1;
            }
        }

        return ans;
    }
};
