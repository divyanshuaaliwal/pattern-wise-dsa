// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:

// Index:        0 .................. firstIndex   ......................  secondIndex ........ n-1
//               [ elements with 2 duplicates  ]   [ duplicate elements ]  [    not processed     ]


    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 0 || n == 1 || n == 2) {
            return n;
        }

        int firstIndex = 1;
        int secondIndex = 2;

        while(secondIndex < n) {
            if(nums[firstIndex - 1] != nums[secondIndex]) {
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
