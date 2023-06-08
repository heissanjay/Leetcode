class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count {0};
        int col = grid[0].size();
        
        for (auto& row: grid) {
            int idx = upper_bound(row.begin(), row.end(),0, greater<int>()) - row.begin();
            count += (col - idx);
        }
        return count;
    }
};