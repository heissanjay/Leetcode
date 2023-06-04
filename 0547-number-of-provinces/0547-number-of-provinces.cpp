class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && isConnected[i][j] == 1) {
                    count++;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        
                        int r = curr.first;
                        int c = curr.second;
                        
                        visited[r][c] = true;
                        
                        // Explore neighbors
                        for (int k = 0; k < m; k++) {
                            if (!visited[c][k] && isConnected[c][k] == 1) {
                                q.push({c, k});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
