// URL: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
        
        int index = nums1.size() - 1;
        int firstIndex = n1 - 1;
        int secondIndex = n2 - 1;
        
        while(firstIndex >= 0 && secondIndex >= 0) {
            if(nums1[firstIndex] < nums2[secondIndex]) {
                nums1[index] = nums2[secondIndex];
                secondIndex -= 1;
                index -= 1;
            }
            else {
                nums1[index] = nums1[firstIndex];
                firstIndex -= 1;
                index -= 1;
            }
        }

        while(secondIndex >= 0) {
            nums1[index] = nums2[secondIndex];
            secondIndex -= 1;
            index -= 1;
        }
    }
};
