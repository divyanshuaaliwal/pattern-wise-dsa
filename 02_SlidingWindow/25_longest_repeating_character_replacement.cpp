// URL: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:

    int getMaxFreq(unordered_map <char, int>& mpp) {
        int maxFreq = 0;
        for(auto itr: mpp) {
            maxFreq = max(maxFreq, itr.second);
        }
        return maxFreq;
    }

    int characterReplacement(string s, int k) {
        
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = 0;
        unordered_map <char, int> mpp;
      
        while(j < n) {
        
            mpp[s[j]] += 1;
            
            int currWinMaxFreq = getMaxFreq(mpp);

            while(i <= j && (j - i + 1) - currWinMaxFreq > k) {
                mpp[s[i]] -= 1;
                i += 1;
                currWinMaxFreq = getMaxFreq(mpp);
            }

            if(i <= j &&  (j - i + 1) - currWinMaxFreq == k) {
                maxLen = max(maxLen, j - i + 1);
            }

            if(i <= j &&  (j - i + 1) - currWinMaxFreq < k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j += 1;
        }
        
        return maxLen;
    }
};
