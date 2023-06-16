class Solution {
private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;
    
    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if ( m < 3) return 1;
        
        vector<int> leftChilds, rightChilds;
        
        for (int i = 1; i < m; i++){
            if (nums[i] < nums[0]) {
                leftChilds.push_back(nums[i]);
            } else {
                rightChilds.push_back(nums[i]);
            }
        }
        
        long long leftCount = dfs(leftChilds) % mod;
        long long rightCount = dfs(rightChilds) % mod;
        
        return (
       ( (leftCount * rightCount) % mod )
            *
        table[m-1][leftChilds.size()]
        ) % mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n+1);
        for (int i = 0; i < n; i++){
            table[i] = vector<long long>(i+1,1);
            for (int j =1; j < i; j++) {
                table[i][j] = 
                    (table[i-1][j-1] 
                    +
                     table[i-1][j]
                    )% mod;
            }
        }
        return (dfs(nums) -1) % mod;
    }
};