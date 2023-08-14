#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int solve(int i,string&s,vector<int>&dp){
        if(i == s.length()) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;
        int ans = solve(i + 1,s,dp);
        if(i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ans += solve(i + 2,s,dp);
        return dp[i] = ans;
    }
    int numDecodings(string s){
        int n = s.length();
        vector<int> dp(n + 1,-1);
        return solve(0,s,dp);
    }
};
int main(){
    string s;
    Solution sol;
    cout << sol.numDecodings(s);
    return 0;
}