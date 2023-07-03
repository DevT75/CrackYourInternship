#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        else return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }

    // 1 <= n <= 46

    int climbStairs(int n) {
    	// Vector is of fixed size becase of the constraints
        vector<int> dp(46,-1);
        return solve(n,dp);
    }
};

int main(){
	int n;
	cin >> n;
	Solution s;
	cout << s.climbStairs(n) << "\n";
	return 0;
}