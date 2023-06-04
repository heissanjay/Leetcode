//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1') {
            return;
        }

        grid[x][y] = '0';  // Mark the current cell as visited

        // Define the possible directions to explore
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Horizontal and vertical
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  // Diagonal
        };

        // Explore all neighboring cells
        for (pair<int, int> dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            dfs(nx, ny, n, m, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();

        int count = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return count;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends