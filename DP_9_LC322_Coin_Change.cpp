#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <utility>
using namespace std;

class Solution {
public:
    // int solve(vector<int>& coins,int n, int amount,vector<vector<int>>&dp){
    //     if(amount == 0) return 0;
    //     if(n == 0) return 1e9;
    //     if(dp[n][amount] != -1) return dp[n][amount];
    //     if(coins[n-1] <= amount){
    //         int op1 = 1 + solve(coins,n,amount-coins[n-1],dp);
    //         int op2 = solve(coins,n-1,amount,dp);
    //         return dp[n][amount] = min(op1,op2);
    //     }
    //     else return dp[n][amount] = solve(coins,n-1,amount,dp);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n + 1,vector<int>(amount + 1,-1));
    //     int ans = solve(coins,n,amount,dp);
    //     return ans == 1e9 ? -1 : ans;
    // }


    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> prev(amount + 1,1e9);
    //     int n = coins.size();
    //     prev[0] = 0;
    //     for(int i = 1;i < n + 1;i++){
    //         for(int j = 1;j < amount + 1;j++){
    //             if(coins[i-1] <= j) prev[j] = min(1 + prev[j-coins[i-1]], prev[j]);
    //             else prev[j] = prev[j];
    //         }
    //     }
    //     int ans = prev[amount];
    //     if(ans >= 1e9) return -1;
    //     return prev[amount];
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1,1e9);
        for(int i = 0;i <= amount;i++){
            if(i == 0) dp[i] = 0;
            else for(int j : coins){
                if(j <= i) dp[i] = min(dp[i],1 + dp[i-j]);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

int main(){
    int n,amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0;i < n;i++) cin >> coins[i];
    Solution s;
    cout << s.coinChange(coins,amount) << "\n";
    return 0;
}