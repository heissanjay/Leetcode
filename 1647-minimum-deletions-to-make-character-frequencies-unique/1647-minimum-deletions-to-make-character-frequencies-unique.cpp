class Solution {
public:
    int minDeletions(string s) {
        unordered_map <char,int> freqTable;
        unordered_set<int> uniqueFrequencies;
        
        int count {0};
        
        for (auto& item: s) {
            freqTable[item]++;
        }
        
        for (const auto& it: freqTable) {            
            int frequency = it.second;
            while (uniqueFrequencies.count(frequency) > 0 && frequency > 0) {
                frequency--;
                count++;
            }
            
            uniqueFrequencies.insert(frequency);
        }
        
        return count;
        
    }
};