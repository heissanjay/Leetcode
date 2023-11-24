class Solution {

    private void helper(int i, int[] candidates, int target, int currentSum, List<Integer> subset, List<List<Integer>> solutionSet) {
        // base case
        if (currentSum == target) {
            solutionSet.add(new ArrayList<>(subset));
            return;
        }

        if (i >= candidates.length  || currentSum > target) {
            return;
        }
        
                // take it
        subset.add(candidates[i]);
        currentSum += candidates[i];
        helper(i + 1, candidates, target, currentSum, subset, solutionSet);
        subset.remove(subset.size() - 1);
        currentSum -= candidates[i];

        
        // skip duplicates
        while (i < candidates.length - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }

        // skip it
        helper(i + 1, candidates, target, currentSum, subset, solutionSet);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<Integer> subset = new ArrayList<>();
        List<List<Integer>> solutionSet = new ArrayList<>();
        Arrays.sort(candidates);
        helper(0, candidates, target, 0, subset, solutionSet);
        return solutionSet;
    }
}