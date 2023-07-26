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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> pendingNodes;
        vector<vector<int>> ans;
        if(!root) return ans;
        pendingNodes.push(root);
        while(pendingNodes.size() > 0){
            vector<int>temp;
            int n = pendingNodes.size();
            while(n--){
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                temp.push_back(front->val);
                if(front->left) pendingNodes.push(front->left);
                if(front->right) pendingNodes.push(front->right);
            }
            ans.push_back(temp);
        }
    return ans;
    }
};