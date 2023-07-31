#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    void solve(int i,int j,vector<vector<int>>&m,vector<vector<bool>>&vis,int n,string x,
        vector<string>&ans){
        if(i == n - 1 && j == n - 1 && m[i][j] == 1){
            ans.push_back(x);
            return;
        }
        vis[i][j] = true;
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1 };
        char ch[] = { 'U', 'R', 'D', 'L' };
        for(int k = 0;k < 4;k++){
            int r = i + delRow[k];
            int c = j + delCol[k];
            if(r >= 0 && r < n && c >= 0 && c < n && !vis[r][c] && m[r][c] == 1){
                x.push_back(ch[k]);
                vis[r][c] = true;
                solve(r,c,m,vis,n,x,ans);
                vis[r][c] = false;
                x.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1] == 0 || m[0][0] == 0) return {};
        string x = "";
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<string> ans;
        solve(0,0,m,vis,n,x,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<vector<int>> m(n,vector<int>(n));
    for(int i = 0;i < n;i++) for(auto &j : m[i]) cin >> j;
    Solution s;
    auto ans = s.findPath(m,n);
    for(string& x : ans) cout << x << "\n";
    return 0;
}