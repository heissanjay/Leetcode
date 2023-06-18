class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int mod = 1e9 + 7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != 0)
            return dp[i][j];
        
        int answer = 1;
        
        for (auto& d : directions) {
            int prevI = i + d[0];
            int prevJ = j + d[1];
            
            if (prevI >= 0 && prevI < grid.size() && prevJ >= 0 && prevJ < grid[0].size() && grid[prevI][prevJ] < grid[i][j]) {
                answer += dfs(grid, prevI, prevJ);
                answer %= mod;
            }
        }
        
        dp[i][j] = answer;
        return answer;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<int>(n, 0));
        
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer = (answer + dfs(grid, i, j)) % mod;
            }
        }
        
        return answer;
    }
};
