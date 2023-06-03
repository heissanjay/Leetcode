class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = INT_MIN;
        vector<int> sub_empl[n];
        for (int i = 0; i < n; i++){
            if (manager[i] != -1) sub_empl[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q; // <empl.id, inf.time>
        q.push({headID, 0});
        
        while (!q.empty()){
            pair<int,int> manager = q.front();
            q.pop();
            
            int lead = manager.first;
            int time = manager.second;
            
            maxTime = max(maxTime, time);
            
            for (auto employee: sub_empl[lead]){
                q.push({employee, time + informTime[lead]});
            }
        }
        return maxTime;
    }
};