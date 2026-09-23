// URL: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int i = 0;
        int j = 0;
        int n = s.size();
        int windowSize = p.size();
        
        unordered_map <char, int> mpp;
        for(char ch: p) {
            mpp[ch] += 1;
        }
        
        int count = mpp.size();
        vector <int> ans;
        
        while(j < n) {
            
            if(mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]] -= 1;
                if(mpp[s[j]] == 0) {
                    count -= 1;
                }
            }
            
            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                if(count == 0) {
                    ans.push_back(i);
                }
    
                if(mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]] += 1;
                    if(mpp[s[i]] == 1) {
                        count += 1;
                    }
                }
            
                i += 1;
                j += 1;
            }
        }
        
        return ans;
    }
};
