class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (n != m) return false;
        
        unordered_map<char,int> freqMap;
        
        for (char ch: s) {
            freqMap[ch]++;
        }
        
        for (char ch: t) {
            if (freqMap.find(ch) == freqMap.end() || freqMap[ch] == 0) return false;
            
            freqMap[ch]--;
        }
        return true;
    }
};