class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size())  return nums;
        unordered_map<int,int> mapp;
        for (int i = 0; i < nums.size(); ++i)  {
            mapp[nums[i]]++;
        }
        auto comp = [&mapp](int n1,int n2) {
            return mapp[n1] > mapp[n2];
        };
        priority_queue<int,vector<int>, decltype(comp) > heap(comp);
        
        for (pair<int,int> it: mapp) {
            heap.push(it.first);
            if (heap.size() > k) heap.pop();
        }
        vector<int> top(k);
        for (int i = k -1; i >=0 ; --i) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};