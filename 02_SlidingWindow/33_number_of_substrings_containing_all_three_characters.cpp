// URL: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:

    int countAtMostK(string s, int k) {
        
        int i = 0;
        int j = 0;
        int totalSubarrays = 0;
        unordered_map <int, int> mpp;
        int n = s.size();

        while(j < n) {
            
            mpp[s[j]] += 1;

            while(i <= j && mpp.size() > k) {
                mpp[s[i]] -= 1;
                if(mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i += 1;
            }

            if(i <= j && mpp.size() == k) {
                totalSubarrays += (j - i + 1);
            }
                        
            if(i <= j && mpp.size() < k) {
                totalSubarrays += (j - i + 1);
            }

            j += 1;
        }

        return totalSubarrays;
    }

    int numberOfSubstrings(string s) {
        int k = 3;
        return countAtMostK(s, k) - countAtMostK(s, k - 1);      
    }
};