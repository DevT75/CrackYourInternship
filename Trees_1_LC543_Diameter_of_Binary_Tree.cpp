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
    pair<int,int> solve(TreeNode* root){

        if(!root) return { 0,0 };

        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);

        int op1 = l.second;
        int op2 = r.second;
        int op3 = 1 + l.first + r.first;

        return { 1 + max(l.first,r.first), max(op1,max(op2,op3)) };
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return ans.second-1;
    }
};