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
    void flatten(TreeNode* &root){
        if(!root) return;
        stack<pair<int,TreeNode*>> s;
        s.push({1,root});
        vector<TreeNode*> preOrder;
        while(!s.empty()){
            TreeNode*currNode = s.top().second;
            int state = s.top().first;
            if(state == 1){
                s.top().first++;
                if(currNode->left) s.push({1,currNode->left});
                preOrder.push_back(currNode);
            }
            else if(state == 2){
                s.top().first++;
                if(currNode->right) s.push({1,currNode->right});
            }
            else s.pop();
        }
        root = preOrder[0];
        TreeNode*tail = root;
        for(int i = 1;i < preOrder.size();i++){
            tail->right = preOrder[i];
            tail->left = NULL;
            tail = tail->right;
        }
    }
};