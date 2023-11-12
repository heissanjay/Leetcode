class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapp;
        vector<vector<string>> result;
        
        for (auto it : strs) {
            string word = it;
            sort(word.begin(), word.end());
            mapp[word].push_back(it);
        }
        
        for (auto it: mapp) {
            result.push_back(it.second);
        }
        return result;
    }
};