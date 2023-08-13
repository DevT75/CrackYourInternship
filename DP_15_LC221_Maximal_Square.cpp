#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
	// DP Solution
	// The idea is to get the maximal side of square
	// recurrence is defined as dp(i,j) = 1 + min(dp(i-1,j-1),dp(i,j-1),dp(i-1,j))
	// since we are calculating the ans in bottom right manner for curr cell to be the
	// bottom right corner of a square of square of side n the alll three up left cells
	// should be equal else the cell will extend the minimum square
	// 
	// The catch here is that for a cell (i, j) to be botttom corner
	//  for a sqaure of length n lets say 3, 
	// cells [i-1, j], [i-1, j-1], [i, j-1], all three shoule be bottom 
	// right of a square of length n-1 e.g. of length 2.
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j]-'0';
                else
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) ans = max(ans,dp[i][j]);
        }
        return ans*ans;
    }
};

int main(){
	int m,n;cin >> m >> n;
	vector<vector<char>> matrix(m,vector<char>(n));
	for(auto &i : matrix) for(auto &j : i) cin >> j;
	Solution s;
	cout << s.maximalSquare(matrix);
	return 0;
}