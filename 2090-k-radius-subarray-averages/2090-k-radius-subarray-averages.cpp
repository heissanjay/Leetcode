class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n,-1);
        vector<long long> prefix(n+1,0);
        
        if (k == 0) return nums;
        
        if (n < 2 * k + 1) return avgs;
        
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        for (int j = k; j < (n -k); ++j) {
            int leftSubArr = j - k; // boundary
            int rightSubArr = j + k;
            
            long long subArr = prefix[rightSubArr + 1] - prefix[leftSubArr];
            int avg = subArr / (2 * k + 1);
            
            avgs[j]=avg;            
        }
        return avgs;
    }
};