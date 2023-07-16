#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution{
public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        int ans = 0;
        for(int i = 0;i < n + 1;i++){
            for(int j  = 0;j < m + 1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	Solution s;
	cout << s.longestCommonSubstr(s1,s2,s1.length(),s2.length());
	return 0;
}
