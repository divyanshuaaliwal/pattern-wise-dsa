// URL: https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& str) {
        
        int n = str.size();
        int start = 0;
        int end = n - 1;

        while(start <= end) {  
            swap(str[start], str[end]);
            start += 1;
            end -= 1;
        }
    }
};
