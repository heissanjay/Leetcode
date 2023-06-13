class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mapp;
        int n = grid.size();
        int m = grid[0].size();
        int count {
          0
        };

        for (vector<int> row: grid){
          mapp[row]++;
        }

        for (int i = 0; i < n; i++) {
          vector<int> getColumn = {
          };

          for (int j = 0; j < m; j++) {
            getColumn.push_back(grid[j][i]); // access the elements column wise
          }
          count += mapp[getColumn];
        }

        return count;
    }
};