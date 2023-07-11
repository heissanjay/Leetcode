class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, parentMap, nullptr);
        
        vector<int> result;
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> queue;
        queue.push(target);
        visited.insert(target);
        
        int currDistance = 0;
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            
            if (currDistance == k) {
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = queue.front();
                    queue.pop();
                    result.push_back(node->val);
                }
                break;
            }
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if (node->left && visited.find(node->left) == visited.end()) {
                    queue.push(node->left);
                    visited.insert(node->left);
                }
                
                if (node->right && visited.find(node->right) == visited.end()) {
                    queue.push(node->right);
                    visited.insert(node->right);
                }
                
                TreeNode* parent = parentMap[node];
                
                if (parent && visited.find(parent) == visited.end()) {
                    queue.push(parent);
                    visited.insert(parent);
                }
            }
            
            currDistance++;
        }
        
        return result;
    }
    
private:
    void buildParentMap(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* parent) {
        if (!node)
            return;
        
        parentMap[node] = parent;
        buildParentMap(node->left, parentMap, node);
        buildParentMap(node->right, parentMap, node);
    }
};
