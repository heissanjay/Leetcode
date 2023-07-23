class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
        return {};
    }

    if (n == 1) {
        return { new TreeNode(0) };
    }

    vector<TreeNode*> result;
    for (int left_nodes = 1; left_nodes < n; left_nodes += 2) {
        int right_nodes = n - 1 - left_nodes;
        vector<TreeNode*> left_subtrees = allPossibleFBT(left_nodes);
        vector<TreeNode*> right_subtrees = allPossibleFBT(right_nodes);

       
        for (TreeNode* left : left_subtrees) {
            for (TreeNode* right : right_subtrees) {
                TreeNode* root = new TreeNode(0);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
    
    }
};