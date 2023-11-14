class Solution {
private:
    // some helper functions to filter the chars
    
    bool isUpperCaseAlpha (char c) {
        return (c >= 'A' && c <= 'Z');
    }
    
    bool isLowerCaseAlpha (char c) {
        return (c >= 'a' && c <= 'z');
    }
    
    bool isNumeric (char c) {
        return (c >= '0' && c <= '9');
    }
    
    
public:
    bool isPalindrome(string s) {
        int n =  s.length();
        
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            
            while (i < j && !isUpperCaseAlpha(s[i]) && !isLowerCaseAlpha(s[i]) && !isNumeric(s[i])) i++;
            while (i < j && !isUpperCaseAlpha(s[j]) && !isLowerCaseAlpha(s[j]) && !isNumeric(s[j])) j--;
            
            if ( i > j || tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;            
        }
        
        return true;
    }
};