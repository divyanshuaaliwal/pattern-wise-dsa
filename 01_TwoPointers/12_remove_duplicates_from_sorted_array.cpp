// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:

// Index:        0 ........ firstIndex   ......................  secondIndex ........ n-1
//               [  unique elements  ]   [ duplicate elements ]  [    not processed     ]


    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int firstIndex = 0;
        int secondIndex = 1;

        while(secondIndex < n) {
            if(nums[firstIndex] != nums[secondIndex]) {
                nums[firstIndex + 1] = nums[secondIndex];
                firstIndex += 1;
                secondIndex += 1;
            }
            else {
                secondIndex += 1;
            }
        }

        return firstIndex + 1;
    }
};
