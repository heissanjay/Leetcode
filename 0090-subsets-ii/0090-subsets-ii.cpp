class Solution {
private:
    void helper(int start, vector<int>& nums, vector<vector<int>>& solutionSet, vector<int>& subset) {
        solutionSet.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.push_back(nums[i]);
            helper(i + 1, nums, solutionSet, subset);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> solutionSet;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        helper(0, nums, solutionSet, subset);
        return solutionSet;
    }
};
