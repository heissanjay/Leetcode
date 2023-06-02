class Solution {
private:
    int dfs(int i, unordered_map<int,vector<int>>& graph) {
        stack<int> st;
        set<int> visited;
        st.push(i);
        visited.insert(i);
        
        while(!st.empty()) 
        {
            int cur = st.top();
            st.pop();
            for(auto neib: graph[cur]){
                if (!visited.count(neib)){
                    visited.insert(neib);
                    st.push(neib);
                }
            }
        }
        return visited.size();
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> graph;
        int n = bombs.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];
                
                if (
                (long) ri * ri >= (long) (xi - xj) * (xi - xj) + 
                (long) (yi - yj) * (yi - yj)
                ) {
                    graph[i].push_back(j);
                }
            }
        }
        int ans {0};
        for (int i = 0; i < n; i++) {
            ans = max(ans,dfs(i,graph));
        }
        return ans;
    }
};