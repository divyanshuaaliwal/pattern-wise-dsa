// URL: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:

    bool isValidWindow(unordered_map<char, int>mpp, int k) {
        if(mpp['a'] < k || mpp['b'] < k || mpp['c'] < k) {
            return false;
        }
        return true;
    }

    int takeCharacters(string s, int k) {
        
        int i = 0;
        int j = 0;
        int n = s.size();

        unordered_map <char, int> mpp;
        int maxLen = 0;

        for(char ch: s) {
            mpp[ch] += 1;
        }

        if(!isValidWindow(mpp, k)) {
            return -1;
        }

        while(j < n) {

            mpp[s[j]] -= 1;

            while(i <= j && !isValidWindow(mpp, k)) {
                mpp[s[i]] += 1;
                i += 1;
            }

            maxLen = max(maxLen, j-i+1);

            j += 1;
        }

        return n - maxLen;
    }
};
