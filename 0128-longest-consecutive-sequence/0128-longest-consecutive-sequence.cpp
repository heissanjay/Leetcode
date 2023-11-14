class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int res = 1;

        for (const auto& num : s) {

            if (s.find(num - 1) == s.end()) {
                int count = 1;
                int x = num + 1;

                
                while (s.find(x) != s.end()) {
                    x += 1;
                    count += 1;
                }

                res = max(res, count);
            }
        }

        return res;
    }
};