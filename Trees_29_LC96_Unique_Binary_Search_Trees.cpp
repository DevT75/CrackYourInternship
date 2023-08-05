#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans += solve(i,dp)*solve(n-i-1,dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1,-1);
        dp[0] = 1;
        return solve(n,dp);
    }
};
int main(){
    int n;
    cin >> n;
    Solution s;
    cout << s.numTrees(n);
    return 0;
}