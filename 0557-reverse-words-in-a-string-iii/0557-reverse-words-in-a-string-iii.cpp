class Solution {
private:
    string reverseWord(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    
        return s;
    }
public:
    string reverseWords(string s) {
        string reversed, word;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i]; 
            } else {
                reversed += reverseWord(word);
                reversed += " "; 
                word = "";
            }
        }

        
        if (!word.empty()) {
            reversed += reverseWord(word);
        }

        return reversed;
    }
};
