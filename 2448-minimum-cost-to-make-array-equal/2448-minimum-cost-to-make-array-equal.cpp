class Solution {
public:
    long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<vector<int>> numsAndCost(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
        }
        sort(numsAndCost.begin(), numsAndCost.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<long long> prefixCost(n);
        
        prefixCost[0] = numsAndCost[0][1];
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i][1] + prefixCost[i - 1];

        long long totalCost = 0;
        for (int i = 1; i < n; ++i)
            totalCost += 1LL * numsAndCost[i][1] * (numsAndCost[i][0] - numsAndCost[0][0]);
        long long answer = totalCost;

        for (int i = 1; i < n; ++i) {
            int gap = numsAndCost[i][0] - numsAndCost[i - 1][0];
            totalCost += 1LL * prefixCost[i - 1] * gap;
            totalCost -= 1LL * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = min(answer, totalCost);
        }

        return answer;
    }
};
