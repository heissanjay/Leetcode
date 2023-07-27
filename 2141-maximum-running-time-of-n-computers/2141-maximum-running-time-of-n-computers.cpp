class Solution {
public:
    long long maxRunTime(int n, std::vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long extra = 0;

        for (int i = 0; i < (int)batteries.size() - n; i++) {
            extra += batteries[i];
        }

        for (int i = 0; i < n - 1; i++) {
            long long diff = batteries[batteries.size() - n + i + 1] - batteries[batteries.size() - n + i];
            if (extra < (long long)(i + 1) * diff) {
                return batteries[batteries.size() - n + i] + extra / (long long)(i + 1);
            }

            extra -= (long long)(i + 1) * diff;
        }

        return batteries[batteries.size() - 1] + extra / n;
    }
};
