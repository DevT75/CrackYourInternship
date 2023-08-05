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
    vector<TreeNode*> helper(int start,int end,
    map<pair<int,int>,vector<TreeNode*>>&m){
        if(start > end) return {NULL};
        vector<TreeNode*> ans;
        if(m.find({ start,end }) != m.end()) return m[{start,end}];
        for(int i = start;i <= end;i++){
            auto left = helper(start,i - 1,m);
            auto right = helper(i + 1,end,m);
            for(auto l : left){
                for(auto r : right){
                    TreeNode*root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
                m[{start,end}] = ans;
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n){
        map<pair<int,int>,vector<TreeNode*>> m;
        helper(1,n,m);
        return helper(1,n,m);
    }
};