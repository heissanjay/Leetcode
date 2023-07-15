class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans {1};
        for (int a : arr){
            int beforeA = dp.count(a-difference)? dp[a -difference] : 0;
            dp[a] = beforeA +1 ;
            ans = max(ans, dp[a]);
        }
        return ans;
    }
};