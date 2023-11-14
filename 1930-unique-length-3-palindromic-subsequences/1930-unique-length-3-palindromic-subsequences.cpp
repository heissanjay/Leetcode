class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> chars;
        
        for (char c: s) {
            chars.insert(c);
        }
        
        int ans {0};
        
        for (char c: chars) {
            int i = -1;
            int j = 0;
            
            for(int k = 0; k < s.size(); k++) {
                if (s[k] == c) {
                    if (i == -1) {
                        i = k; // first occ
                    }
                    
                    j = k; // last occ
                }
            }
            
            unordered_set<char> middle;
            for (int k = i + 1; k < j; k++) {
                middle.insert(s[k]);
            }
            
            ans += middle.size();
        }
        
        return ans;
    }
};