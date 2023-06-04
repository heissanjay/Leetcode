class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        visited[city] = true;
        
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (!visited[neighbor] && isConnected[city][neighbor] == 1) {
                dfs(isConnected, visited, neighbor);
            }
        }
    }
};
