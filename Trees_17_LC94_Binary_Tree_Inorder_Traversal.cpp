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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> inOrder;
        stack<pair<int,TreeNode*>> s;
        s.push({1,root});
        while(!s.empty()){
            TreeNode*currElement = s.top().second;
            int state = s.top().first;
            if(state == 1){
                s.top().first++;
                if(currElement->left!=NULL)
                    s.push({1,currElement->left});
            }
            else if(state == 2){
                s.top().first++;
                if(currElement->right!=NULL)
                    s.push({1,currElement->right});
                inOrder.push_back(currElement->val);
            }
            else{
                s.pop();
            }
        }
        return inOrder;
    }
};