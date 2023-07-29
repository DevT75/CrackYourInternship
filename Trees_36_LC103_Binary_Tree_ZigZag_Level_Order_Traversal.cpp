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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> s1,s2;
        vector<vector<int>> ans;
        s1.push(root);
        int lvl = 0;
        while(!s1.empty() || !s2.empty()){
            if(lvl % 2 == 0){
                cout << "ye" << " ";
                int n = s1.size();
                vector<int> sa;
                for(int i = 0;i < n;i++){
                    TreeNode*temp = s1.top();
                    s1.pop();
                    if(temp->left) s2.push(temp->left);
                    if(temp->right) s2.push(temp->right);
                    sa.emplace_back(temp->val);
                }
                ans.emplace_back(sa);
                sa.clear();
                lvl++;
            }
            else{
                cout << "br" << " ";
                int n = s2.size();
                vector<int> sa;
                for(int i = 0;i < n;i++){
                    TreeNode*temp = s2.top();
                    s2.pop();
                    if(temp->right) s1.push(temp->right);
                    if(temp->left) s1.push(temp->left);
                    sa.emplace_back(temp->val);
                }
                ans.emplace_back(sa);
                sa.clear();
                lvl++;
            }
        }
        return ans;
    }
};