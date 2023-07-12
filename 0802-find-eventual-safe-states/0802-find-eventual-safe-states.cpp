class Solution {
private:
    bool dfs(int node,vector<vector<int>>& adj, vector<bool>& visited,vector<bool>& inStack){
        if (inStack[node]) return true;
        if (visited[node]) return false;
        
        visited[node] = true;
        inStack[node] = true;
        for (auto neighbor: adj[node]) {
            if (dfs(neighbor, adj, visited, inStack)) return true;
        }
        
        inStack[node]=false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++){
            for (auto node: graph[i]) {
                adj[i].push_back(node);
            }
        }
        vector<bool> visited(n), inStack(n);
        
        for (int i = 0; i < n; i++) {
            dfs(i,adj,visited,inStack);
        }
        vector<int> safeNodes;
        for (int i  = 0; i < n; i++){
            if (!inStack[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};