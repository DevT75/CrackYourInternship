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
    const int mod_1 = 1000000007;
    const int mod_2 = INT_MAX;
    vector<pair<unsigned long long,unsigned long long>> memo;
    pair<unsigned long long,unsigned long long> hash(TreeNode*root,bool need){
        if(!root) return { 3, 7 };
        auto left = hash(root->left,need);
        auto right = hash(root->right,need);

        auto left1 = (left.first << 5) % mod_1;
        auto right1 = (right.first << 1) % mod_1;
        auto left2 = (left.second << 7) % mod_2;
        auto right2 = (right.second << 1) % mod_2;

        pair<unsigned long long,unsigned long long> hashPair = { (left1+right1+root->val)%mod_1,
            (left2+right2+root->val)%mod_2
        };
        if(need) memo.emplace_back(hashPair);
        return hashPair;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        hash(root,true);
        pair<unsigned long long,unsigned long long> s = hash(subRoot,false);
        return find(memo.begin(),memo.end(),s) != memo.end();
    }
};