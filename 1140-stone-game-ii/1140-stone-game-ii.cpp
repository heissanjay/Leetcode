class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Calculate the cumulative sums from the right to left
        vector<int> suffixSum(n + 1, 0);
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                if (i + 2 * M >= n) {
                    // If the remaining piles can be taken in a single turn,
                    // Alice can take all the remaining stones
                    dp[i][M] = suffixSum[i];
                } else {
                    for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                        // Calculate the maximum number of stones Alice can get
                        int remainingStones = dp[i + X][max(M, X)];
                        dp[i][M] = max(dp[i][M], suffixSum[i] - remainingStones);
                    }
                }
            }
        }

        return dp[0][1];
    }
};
