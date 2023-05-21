class Solution {
private:
    vector<vector<int>> bfsQueue;
    void dfs(vector<vector<int>>& grid, int x, int y, int n) {
        grid[x][y] = 2;
        bfsQueue.push_back({x, y});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int curX = x + dir[0];
            int curY = y + dir[1];
            if (0 <= curX && curX < n && 0 <= curY && curY < n && grid[curX][curY] == 1) {
                dfs(grid, curX, curY, n);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }
        bfsQueue.clear();
        dfs(grid, firstX, firstY, n);
        
        int distance = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!bfsQueue.empty()) {
            vector<vector<int>> newBfs;
            for (auto& pair : bfsQueue) {
                int x = pair[0], y = pair[1];
                for (auto& dir : directions) {
                    int curX = x + dir[0];
                    int curY = y + dir[1];
                    if (0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back({curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }
            bfsQueue = newBfs;
            distance++;
        }
        
        return distance;
    }
};
