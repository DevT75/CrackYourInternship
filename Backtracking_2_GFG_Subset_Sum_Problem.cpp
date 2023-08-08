#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int solve(int n,int target,int arr[],vector<vector<int>>&dp){
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        if(arr[n-1] <= target){
            bool op1 = solve(n-1,target-arr[n-1],arr,dp);
            bool op2 = solve(n-1,target,arr,dp);
            return dp[n][target] = op1 || op2;
        }
        else return dp[n][target] = solve(n-1,target,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0;i < N;i++) sum += arr[i];
        if(sum % 2 != 0) return 0;
        vector<vector<int>> dp(N + 1,vector<int>(sum + 1,-1));
        return solve(N,sum/2,arr,dp);
    }
};
int main(){
    int n;cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    Solution s;
    cout << (s.equalPartition(n,arr) == 1 ? "YES" : "NO");
    return 0;
}