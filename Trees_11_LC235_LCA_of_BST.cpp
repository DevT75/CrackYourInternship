/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root) return NULL;
        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        else if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        else return root;   
    }
};