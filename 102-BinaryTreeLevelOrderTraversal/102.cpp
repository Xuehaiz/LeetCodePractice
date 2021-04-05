/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    
    void recursiveAppend(TreeNode* root, int level) {
        if (!root) {
            return;
        }
        
        if (ans.size() == level) {
            ans.resize(ans.size() + 1);
        }
        
        ans[level].push_back(root->val);
        
        recursiveAppend(root->left, level + 1);
        recursiveAppend(root->right, level + 1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        recursiveAppend(root, 0);
        return ans;
    }
};