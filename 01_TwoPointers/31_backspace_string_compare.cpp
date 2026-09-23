// URL: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:

    bool bruteForce(string s, string t) {

        string s1 = "";
        for(char ch : s) {
            if(ch == '#') {
                if(!s1.empty()) {
                    s1.pop_back();
                }
            }
            else {
                s1.push_back(ch);
            }
        }

        string s2 = "";
        for(char ch : t) {
            if(ch == '#') {
                if(!s2.empty()) {
                    s2.pop_back();
                }
            }
            else {
                s2.push_back(ch);
            }
        }

        return s1 == s2;
    }
    
  
    bool better(string s1, string s2) {
        
        int i = 0;
        while(i < s1.size()) {
            if(s1[i] == '#') {
                if(i != 0) {
                    s1.erase(i - 1, 2);
                    i -= 1;
                }
                else {
                    s1.erase(i, 1);
                }
            }
            else {
                i += 1;
            }
        }

        i = 0;
        while(i < s2.size()) {
            if(s2[i] == '#') {
                if(i != 0) {
                    s2.erase(i - 1, 2);
                    i -= 1;
                }
                else {
                    s2.erase(i, 1);
                }
            }
            else {
                i += 1;
            }
        }

        return s1 == s2;
    }

    bool optimalApp(string s1, string s2) {

        int firstIndex = s1.size() - 1;
        int secondIndex = s2.size() - 1;

        while(firstIndex >= 0 || secondIndex >= 0) {

            int totalSkipS1 = 0;
            while(firstIndex >= 0) {
                if(s1[firstIndex] == '#') {
                    totalSkipS1 += 1;
                    firstIndex -= 1;
                }
                else if(totalSkipS1 > 0) {
                    totalSkipS1 -= 1;
                    firstIndex -= 1;
                }
                else {
                    break;
                }
            }

            int totalSkipS2 = 0;
            while(secondIndex >= 0) {
                if(s2[secondIndex] == '#') {
                    totalSkipS2 += 1;
                    secondIndex -= 1;
                }
                else if(totalSkipS2 > 0) {
                    totalSkipS2 -= 1;
                    secondIndex -= 1;
                }
                else {
                    break;
                }
            }

            char ch1 = firstIndex >= 0 ? s1[firstIndex] : '$';
            char ch2 = secondIndex >= 0 ? s2[secondIndex] : '$';

            if(ch1 != ch2) {
                return false;
            }

            firstIndex -= 1;
            secondIndex -= 1;
        }

        return true;
    }

    
    bool backspaceCompare(string s, string t) {
        // return bruteForce(s, t);
        // return better(s, t);
        return optimalApp(s, t);
    }
};
