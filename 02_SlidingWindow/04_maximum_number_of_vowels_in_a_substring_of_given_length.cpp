// URL: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string str, int k) {
        
        int i = 0;
        int j = 0;
        int n = str.size();
        int currVowels = 0;
        int maxVowels = 0;

        while(j < n) {

            currVowels += isVowel(str[j]);

            if(j-i+1 < k) {
                j += 1;
            }
            else {
                maxVowels = max(maxVowels, currVowels);
                currVowels -= isVowel(str[i]);
                i += 1;
                j += 1;
            }
        }

        return maxVowels;
    }
};
