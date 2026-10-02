// URL: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int k = 2;

        int i = 0;
        int j = 0;
        int n = fruits.size();
        int maxLen = 0;
        unordered_map <int, int> mpp;

        while(j < n) {

            mpp[fruits[j]] += 1;

            while(i <= j && mpp.size() > k) {
                mpp[fruits[i]] -= 1;
                if(mpp[fruits[i]] == 0) {
                    mpp.erase(fruits[i]);
                }
                i += 1;
            }

            if(i <= j && mpp.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            if(i <= j && mpp.size() < k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j += 1;
        }

        return maxLen;
    }
};
