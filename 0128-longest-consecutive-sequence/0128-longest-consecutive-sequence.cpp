class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        
        int res {1};
        
        unordered_set<int> s;
        
        for (const auto& num: nums) {
            s.insert(num);
        }
        
        for (const auto& it: s) {
        
            if (s.find(it - 1) == s.end()) {
                int count = 1;
                int x = it;
                
                
                while (s.find(x+1) != s.end()) {
                    x += 1;
                    count += 1;
                }
                
                res = max(res, count);
            }
            
        }
        return res;
    }
};