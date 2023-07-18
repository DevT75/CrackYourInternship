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
private:
    int sum(TreeNode*root,int low,int high){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root) return 0;
        if(root->val < low) return rangeSumBST(root->right,low,high);
        if(root->val > high) return rangeSumBST(root->left,low,high);
        if(root->val >= low && root->val <= high)
            return root->val + sum(root->left,low,high) + sum(root->right,low,high);
        else return 0;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root) return 0;
        if(root->val < low) root->left = NULL;
        if(root->val > high) root->right = NULL;
        if(root->val >= low && root->val <= high)
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        return rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};