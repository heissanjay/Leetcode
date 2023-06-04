//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> bfsList;
        
        int node = 0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            visited[currNode] =true;
            bfsList.push_back(currNode);
            
            for(auto node: adj[currNode]){
                if (!visited[node]){
                    visited[node] = true;
                    q.push(node);
                }
            }
            
        }
        return bfsList;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends