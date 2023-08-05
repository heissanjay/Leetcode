class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<vector<TreeNode*>>> memo(n + 1, vector<vector<TreeNode*>>(n + 1));
        return generateTreesHelper(1, n, memo);
    }

private:
    vector<TreeNode*> generateTreesHelper(int start, int end, vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) {
            return {nullptr};
        }

        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        vector<TreeNode*> result;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = generateTreesHelper(start, i - 1, memo);
            vector<TreeNode*> rightSubtrees = generateTreesHelper(i + 1, end, memo);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return memo[start][end] = result;
    }
};