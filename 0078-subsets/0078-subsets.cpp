class Solution {
private:
    void helper(int i, vector<int>& nums, vector<vector<int>>& solutionSet, vector<int>& subset) {
        if ( i >= nums.size()) {
            solutionSet.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        helper(i+1, nums, solutionSet, subset);
        subset.pop_back();
        
        helper(i+1, nums, solutionSet, subset);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutionSet;
        vector<int> subset;
        helper(0,nums,solutionSet,subset);
        return solutionSet;
    }
};