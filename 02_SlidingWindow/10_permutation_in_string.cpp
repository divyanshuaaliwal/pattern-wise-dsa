// URL: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int i = 0;
        int j = 0;
        int n = s2.size();
        int windowSize = s1.size();
        
        unordered_map <char, int> mpp;
        for(char ch: s1) {
            mpp[ch] += 1;
        }
        
        int count = mpp.size();
        
        while(j < n) {
            
            if(mpp.find(s2[j]) != mpp.end()) {
                mpp[s2[j]] -= 1;
                if(mpp[s2[j]] == 0) {
                    count -= 1;
                }
            }
            
            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                if(count == 0) {
                    return true;
                }
    
                if(mpp.find(s2[i]) != mpp.end()) {
                    mpp[s2[i]] += 1;
                    if(mpp[s2[i]] == 1) {
                        count += 1;
                    }
                }
            
                i += 1;
                j += 1;
            }
        }
        
        return false;        
    }
};
