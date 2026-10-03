// URL: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
    
        unordered_map <char, int> mpp;
        for(char ch: t) {
            mpp[ch] += 1;
        }

        int count = mpp.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        int firstIndex = -1;
        int minLen = INT_MAX;

        while(j < n) {
            
            if(mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]] -= 1;
                if(mpp[s[j]] == 0) {
                    count -= 1;
                }
            }

            while(i <= j && count == 0) {
                
                if(minLen > j - i + 1) {
                    minLen = min(minLen, j - i + 1);
                    firstIndex = i;
                }
                
                if(mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]] += 1;
                    if(mpp[s[i]] == 1) {
                        count += 1;
                    }
                }
            
                i += 1;    
            } 

            j += 1;
        }

        return firstIndex == -1 ? "" : s.substr(firstIndex, minLen);
    }
};
