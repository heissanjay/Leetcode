class Solution {
    private long helper(int i, int[] nums, long currentResult, int count) {
        if (i >= nums.length) {
            return count == 0 ? Integer.MIN_VALUE : currentResult;
        }

        long takeIt = helper(i + 1, nums, currentResult * nums[i], count + 1);
        long skipIt = helper(i + 1, nums, currentResult, count);

        return Math.max(takeIt, skipIt);
    }

    public long maxStrength(int[] nums) {
        return helper(0, nums, 1, 0);
    }
}
