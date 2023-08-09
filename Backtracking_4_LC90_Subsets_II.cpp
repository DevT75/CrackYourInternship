#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&ans,int n){
        if(i == n){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i + 1,nums,temp,ans,n);
        temp.pop_back();
        solve(i + 1,nums,temp,ans,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans,nums.size());
        vector<vector<int>> a;
        for(auto i : ans) a.push_back(i);
        return a;
    }
};
int main(){
    int n;cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;
    Solution s;
    auto ans = s.subsetsWithDup(nums);
    for(auto i : ans){
        if(i.size() == 0) cout << "{}";
        else for(auto j : i) cout << j << " ";
        cout << "\n";
    }


    return 0;
}