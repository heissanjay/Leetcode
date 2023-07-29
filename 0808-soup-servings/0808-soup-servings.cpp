class Solution {
    private:
    double dp(int a, int b, unordered_map<int, unordered_map<int, double>>& memo) {
        if (a <= 0 && b <= 0) {
           
            return 0.5;
        }
        if (a <= 0) {
            
            return 1.0;
        }
        if (b <= 0) {
           
            return 0.0;
        }

       
        if (memo.count(a) && memo[a].count(b)) {
            return memo[a][b];
        }

       
        double prob = 0.0;
        prob += 0.25 * dp(a - 4, b, memo); // Serve 100 ml of soup A and 0 ml of soup B
        prob += 0.25 * dp(a - 3, b - 1, memo); // Serve 75 ml of soup A and 25 ml of soup B
        prob += 0.25 * dp(a - 2, b - 2, memo); // Serve 50 ml of soup A and 50 ml of soup B
        prob += 0.25 * dp(a - 1, b - 3, memo); // Serve 25 ml of soup A and 75 ml of soup B

        memo[a][b] = prob;
        return prob;
    }
public:
    double soupServings(int n) {
        if (n >= 5000) {
            return 1.0;
        }
        n = (n + 24) / 25;
        unordered_map<int, unordered_map<int, double>> memo;
        return dp(n, n, memo);
    }
};
