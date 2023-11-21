class Solution {
 public int countExpression(int[] nums, int target, int index, int currentSum) {
        int count = 0;
        if (index == nums.length) {
            return (currentSum == target) ? 1 : 0;
        }
        
        count += countExpression(nums, target, index + 1, currentSum + nums[index]);
        count += countExpression(nums, target, index + 1, currentSum - nums[index]);
    
        return count;
    }
    
    
    public int findTargetSumWays(int[] nums, int target) {
        return countExpression(nums, target, 0, 0);
    }
}