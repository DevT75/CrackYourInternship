#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&grid,int m,int n){
        if(m == 1 && n == 1) return grid[m-1][n-1];
        if(dp[m][n] != -1) return dp[m][n];
        int right = n > 1 ? solve(grid,m,n-1) : INT_MAX;
        int bottom = m > 1 ? solve(grid,m-1,n) : INT_MAX;
        return dp[m][n] = grid[m-1][n-1] + min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,m,n);
    }
};

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> grid[i][j];
    Solution s;
    cout << s.minPathSum(grid) << "\n";
    return 0;
}