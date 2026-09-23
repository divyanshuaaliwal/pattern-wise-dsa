// URL: https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution {
  public:
    int search(string &pat, string &txt) {
        
        int i = 0;
        int j = 0;
        int n = txt.size();
        int windowSize = pat.size();
        
        unordered_map <char, int> mpp;
        for(char ch: pat) {
            mpp[ch] += 1;
        }
        
        int count = mpp.size();
        int totalAnagrams = 0;
        
        while(j < n) {
            
            if(mpp.find(txt[j]) != mpp.end()) {
                mpp[txt[j]] -= 1;
                if(mpp[txt[j]] == 0) {
                    count -= 1;
                }
            }
            
            if(j-i+1 < windowSize) {
                j += 1;
            }
            else {
                
                if(count == 0) {
                    totalAnagrams += 1;
                }
    
                if(mpp.find(txt[i]) != mpp.end()) {
                    mpp[txt[i]] += 1;
                    if(mpp[txt[i]] == 1) {
                        count += 1;
                    }
                }
            
                i += 1;
                j += 1;
            }
        }
        
        return totalAnagrams;
    }
};
