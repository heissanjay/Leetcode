class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int n = s.length();

        while (end < n) {
            
            while (start < n && s[start] == ' ') {
                start++;
            }

            end = start;
            while (end < n && s[end] != ' ') {
                end++;
            }

            
            reverse(s.begin() + start, s.begin() + end);

            
            start = end;
        }

        return s;
    }
};
