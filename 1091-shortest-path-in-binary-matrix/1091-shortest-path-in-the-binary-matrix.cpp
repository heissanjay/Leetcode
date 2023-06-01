class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // no clear path
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        // 8 - directional
        vector<pair<int,int>> moves =  {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first.first;
            int c = curr.first.second;

            int l = curr.second;
            if (r == n - 1 && c == m -1 ) return l;

            vis[r][c] = true;
            for (pair<int,int> move: moves){
                int x = r + move.first, y = c + move.second;

                if (x < 0 || y < 0 || x >= n || y >=n ) continue;
                if (vis[x][y] == false && grid[x][y] == 0) {
                    vis[x][y] = true;
                    q.push({{x,y}, l+1});
                }
            }
        }
        return -1;
    }
};