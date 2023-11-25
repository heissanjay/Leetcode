class Solution {
    private long helper(int i, int[] nums, long currentResult, int count) {
        if ( i >= nums.length) {
            if ( count == 0) {
                return Integer.MIN_VALUE;
            }
            return currentResult;
        }
        
        
        long takeIt = helper(i+1, nums, currentResult * nums[i], count +1 );
        long skipIt = helper(i+1, nums, currentResult, count);
        
        currentResult = Math.max(takeIt,skipIt);
        
        return currentResult;
        
        
    }
    
    public long maxStrength(int[] nums) {
        return helper(0, nums, 1,0);
    }
}