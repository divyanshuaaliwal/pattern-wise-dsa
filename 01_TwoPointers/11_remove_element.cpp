// URL: https://leetcode.com/problems/remove-element/

class Solution {
public:

// Index:        0 ....................   firstIndex............  secondIndex ........ n-1
//               [   elements != val  ]   [    elements == val ]  [    not processed     ]

    int removeElement(vector<int>& nums, int val) {
        
        int firstIndex = 0;
        int secondIndex = 0;
        int n = nums.size();

        while(secondIndex  < n) {
            if(nums[secondIndex] != val) {
                nums[firstIndex] = nums[secondIndex];
                firstIndex += 1;
                secondIndex += 1;
            }
            else {
                secondIndex += 1;
            }
        }

        return firstIndex;
    }
};