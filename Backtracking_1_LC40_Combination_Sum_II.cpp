#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void solve(vector<int>& arr, int target,int i,
    vector<vector<int>>&ans,vector<int>&temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int op = i;op < arr.size();op++){
            if(op > i && arr[op] == arr[op-1]) continue;
            if(arr[op] > target) break;
            temp.push_back(arr[op]);
            solve(arr,target-arr[op],op + 1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};
int main(){
    int n,target;
    cin >> n >> target;
    vector<int> candidates(n);
    for(auto &i : candidates) cin >> i;
    Solution s;
    auto ans = s.combinationSum2(candidates,target);
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}