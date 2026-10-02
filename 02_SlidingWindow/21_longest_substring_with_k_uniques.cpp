// URL: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxLen = -1;
        unordered_map <char, int> mpp;
        
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
                maxLen = max(maxLen, j - i + 1);
            }
            
            j += 1;
        }
        
        return maxLen;
    }
};
