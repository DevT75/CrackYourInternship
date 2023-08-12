#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j];
                else{
                    dp[i][j] = matrix[i][j] == 1 ? 
                    1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])
                     : 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) ans += dp[i][j];
        return ans;
    }
};

int main(){
	int m,n;cin >> m >> n;
	vector<vector<int>> matrix(m,vector<int>(n));
	for(auto &i : matrix) for(auto &j : i) cin >> j;
	Solution s;
	cout << s.countSquares(matrix);
	return 0;
}
