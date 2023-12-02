class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charMap;
        int sum = 0;
        for (const auto& ch : chars) {
            charMap[ch]++;
        }

        for (const auto& word : words) {
            unordered_map<char, int> tempMap = charMap; 

            bool isGood = true;
            for (const auto& ch : word) {
                auto it = tempMap.find(ch);

                if (it != tempMap.end() && it->second > 0) {
                    
                    it->second--;
                } else {
                    
                    isGood = false;
                    break;
                }
            }

           
            if (isGood) {
                sum += word.length();
            }
        }

        return sum;
    }
};