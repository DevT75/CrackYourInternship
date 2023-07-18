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
    bool solve(TreeNode*root,int target){
        if(!root->left && !root->right){
            if(target - root->val == 0) return true;
            return false;
        }
        bool l = false,r = false;
        if(root->left) l = solve(root->left,target-root->val);
        if(root->right) r = solve(root->right,target-root->val);
        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root) return false;
        return solve(root,targetSum);
    }
};