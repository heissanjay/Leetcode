class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum {INT_MIN};
        int maxLevel {0}, currentLevel {0};
        
        queue<TreeNode*> q;
        q.push(root);
        
        while( !q.empty() ) {
            currentLevel+= 1;
            int currentSum {0};
            
            for (int nodes = q.size(); nodes > 0; nodes--){
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
            
            if (currentSum > maxSum){
                maxSum = currentSum;
                maxLevel = currentLevel;
            }
        }
        return maxLevel;
    }
};