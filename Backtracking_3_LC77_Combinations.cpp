#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<int>&v,int k,int i,int l,int r,vector<vector<int>>&ans,vector<int>&temp){
        if(i == k){
            ans.push_back(temp);
            return;
        }
        for(int op = l;op <= r && r - op + 1 >= k - i;op++){
            temp[i] = v[op];
            solve(v,k,i + 1,op + 1,r,ans,temp);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> temp(k);
        vector<int> v(n);for(int i = 0;i < n;i++) v[i] = i + 1;
        vector<vector<int>> ans;
        solve(v,k,0,0,n-1,ans,temp);
        return ans;
    }
};
int main(){
    int n,k;cin >> n >> k;
    Solution s;
    auto ans = s.combine(n,k);
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}