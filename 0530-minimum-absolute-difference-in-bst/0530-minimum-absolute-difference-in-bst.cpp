class Solution {
private:
    int minvalue  {
        INT_MAX
    };
    
    TreeNode* prev = nullptr;
    
    void inOrderTraversal(TreeNode* root){
        if(!root)
            return;
        inOrderTraversal(root->left);
        if (prev != nullptr)
            minvalue = min(minvalue,abs(root->val - prev->val));
        prev = root;
        inOrderTraversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return minvalue;
    }
};