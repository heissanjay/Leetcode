class Solution {

public:
        void dfs(string& src, string& dest, unordered_map<string,vector<pair<string,double>>>&  graph,
    unordered_map<string,int>& visited, double& ans, double temp
            ) {
        if(visited.count(src)) return;
        
        visited[src]++;
        if (src == dest) {
            ans=temp; return;
        }
        
        for (auto it : graph[src]) {
            dfs(it.first, dest, graph, visited, ans, temp*it.second);
        }  
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        unordered_map<string,vector<pair<string,double>>> graph; // {"a", {"b",2.0}}
        
        for (int i = 0 ; i < equations.size(); ++i ) {
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        vector<double> answer(queries.size());
        unordered_map<string,int> visited; // {"a" : "1"} if visited 
        
        for (int i = 0; i < queries.size(); ++i) {
            string start = queries[i][0], end = queries[i][1];
            
            double ans = -1.0;
            visited.clear();
            
            if (graph.count(start)) dfs(start,end,graph,visited,ans,1.0);
            
            answer[i] = ans;
        }
        
        return answer;
    }
};