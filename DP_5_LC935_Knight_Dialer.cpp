#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    long long solve(int i,int j,int n,int dial[][3],vector<vector<long long>>&dp){
        if(i > 3 || j > 2 || i < 0 || j < 0 || dial[i][j] == -1) return 0;
        if(n == 1) return 1;
        if(dp[dial[i][j]][n] != -1) return dp[dial[i][j]][n];
        long long ans = (solve(i-2,j-1,n-1,dial,dp) + solve(i-2,j+1,n-1,dial,dp)
                        + solve(i-1,j-2,n-1,dial,dp) + solve(i-1,j+2,n-1,dial,dp)
                        + solve(i+1,j-2,n-1,dial,dp) + solve(i+1,j+2,n-1,dial,dp)
                        + solve(i+2,j-1,n-1,dial,dp) + solve(i+2,j+1,n-1,dial,dp)) % mod;
        return dp[dial[i][j]][n] = ans;
    }
    int knightDialer(int n) {
        int dial[4][3] = { {1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        int ans = 0;
        vector<vector<long long>> dp(11,vector<long long>(5001,-1));
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 3;j++){
                if(dial[i][j] == -1)continue;
                ans = (ans + solve(i,j,n,dial,dp)) % mod;
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.knightDialer(n);
    return 0;
}