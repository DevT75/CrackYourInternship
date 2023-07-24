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
    bool solve(TreeNode*root,TreeNode*mini,TreeNode*maxi){
        if(!root) return true;
        if(mini && root->val <= mini->val) return false;
        if(maxi && root->val >= maxi->val) return false;
        bool l = solve(root->left,mini,root);
        bool r = solve(root->right,root,maxi);
        return l && r;
    }
    bool isValidBST(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return solve(root,NULL,NULL);
    }
};