class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> mapp;
        vector<vector<string>> result;
        
        for (const auto& str : strs) {
            long long hash = calculateHash(str);
            mapp[hash].emplace_back(str);
        }
        
        for (auto& entry : mapp) {
            result.emplace_back(move(entry.second));
        }
        
        return result;
    }
    
private:
    long long calculateHash(const string& str) {
        const int primeNumbers[26] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
        };

        const long long MOD = 1e9 + 9; 

        long long hash = 1;
        for (char ch : str) {
            hash = (hash * primeNumbers[ch - 'a']) % MOD;
        }

        return hash;
    }
};
