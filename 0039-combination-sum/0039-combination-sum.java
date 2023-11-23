class Solution {
    
    public void helper(int i, int[] candidates, int target, int currentSum, List<Integer> subset, List<List<Integer>> solutionList) {
        
        
        // base case
        if (currentSum == target) {
            solutionList.add(new ArrayList<>(subset));
            return;
        }
        
        if (i >= candidates.length || currentSum > target) {
            return;
        }
        
        // skip it
        helper(i+1, candidates, target, currentSum, subset, solutionList);
        
        // take it
        currentSum += candidates[i];
        subset.add(candidates[i]);
        helper(i, candidates, target, currentSum, subset, solutionList);
               
        
        
        // backtracking  
        currentSum -= candidates[i];
        subset.remove(subset.size() - 1);
        
        
    }
    
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> subset = new ArrayList<>();
        List<List<Integer>> solutionList = new ArrayList<>();
        
        helper(0,candidates, target,0,subset,solutionList);
        
        return solutionList;
    }
}