#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
    int dp[101][101];
    int solve(int m, int n){
        if(m == 1 || n == 1) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int bottom = solve(m-1,n);
        int right = solve(m,n-1);
        return dp[m][n] = bottom + right;
    }
    int uniquePaths(int m, int n){
        memset(dp,-1,sizeof(dp));
        return solve(m,n);
    }
};

int main(){
    int m,n;
    cin >> m >> n;
    Solution s;
    cout << s.uniquePaths(m,n) << "\n";
    return 0;
}