class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> phone_mapping{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;
        string combination;

        function<void(const string&, size_t)> backtrack = [&](const string& remaining_digits, size_t index) {
            if (index == digits.length()) {
                result.push_back(combination);
                return;
            }

            const char digit = digits[index];
            const string& letters = phone_mapping[digit];

            for (char letter : letters) {
                combination.push_back(letter);
                backtrack(remaining_digits, index + 1);
                combination.pop_back();
            }
        };

        backtrack(digits, 0);
        return result;
    }
};
