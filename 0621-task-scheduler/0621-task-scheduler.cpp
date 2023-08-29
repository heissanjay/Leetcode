class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
                
        unordered_map<char,int> taskTable;
        for (auto task: tasks) {
            taskTable[task]++;
        }
        
        priority_queue<int> taskOrder;
        for (auto item: taskTable) {
            taskOrder.push(item.second);
        }
        
        int time =0;
        
        while (!taskOrder.empty()){
            vector<int> temp;
            
            for (int i =0; i <=n; i++){
                if (!taskOrder.empty()){
                    int taskFreq = taskOrder.top();
                    taskOrder.pop();
                    
                    if (taskFreq > 1){
                        temp.push_back(taskFreq - 1);
                    }
                    
                }
                time++;
                if (taskOrder.empty() && temp.empty()){
                    break;
                }
            }
            for (int taskFreq: temp){
                taskOrder.push(taskFreq);
            }
        }
        return time;
    }
};