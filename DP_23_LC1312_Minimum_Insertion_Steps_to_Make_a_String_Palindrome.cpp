#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,-1));
        string y = s;
        reverse(s.begin(),s.end());
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= n;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(y[i-1] == s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n - dp[n][n];
    }
};
int main(){
	string s;
	cin >> s;
	Solution sol;
	cout << sol.minInsertions(s);
	return 0;
}