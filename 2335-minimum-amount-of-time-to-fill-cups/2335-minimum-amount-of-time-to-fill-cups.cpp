class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        int sec = 0;
        while (pq.top() != 0){
            sec++;
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            pq.push(a-1);
            pq.push(b-1);
        }
        
        return sec;
    }
};