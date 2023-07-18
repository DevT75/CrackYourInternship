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
    void inorder(TreeNode*root,vector<int>&nums){
        if(!root) return;
        inorder(root->left,nums);
        nums.emplace_back(root->val);
        inorder(root->right,nums);    
    }
public:
    int getMinimumDifference(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> nums;
        inorder(root,nums);
        int mini = INT_MAX;
        for(int i = 1;i < nums.size();i++) mini = min(mini,nums[i]-nums[i-1]);
        return mini;
    }
};