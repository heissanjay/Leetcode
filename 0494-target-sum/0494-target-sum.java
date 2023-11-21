class Solution {
 public int countExpression(int[] nums, int target, int index, int currentSum, int[][] memo) {
        if (index == nums.length) {
            return (currentSum == target) ? 1 : 0;
        }
        
        if (memo[index][currentSum + 1000] != -1) {
            return memo[index][currentSum + 1000];
        }
        
        int solWithPlus = countExpression(nums, target, index + 1, currentSum + nums[index], memo);
        int solWithMinus = countExpression(nums, target, index + 1, currentSum - nums[index], memo);
        
        memo[index][currentSum + 1000] = solWithPlus + solWithMinus;
        
        return memo[index][currentSum + 1000];
    }
    
    
    public int findTargetSumWays(int[] nums, int target) {
        int[][] memo = new int[nums.length][2001]; 
        
        for (int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        return countExpression(nums, target, 0, 0, memo);
    }
}