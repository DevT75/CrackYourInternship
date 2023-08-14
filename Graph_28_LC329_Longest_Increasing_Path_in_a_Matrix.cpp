#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,
    vector<vector<int>>&dp,int m,int n,int delRow[],int delCol[],int prev){
        if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // vis[i][j] = true;
        int ans = INT_MIN;
        for(int k = 0;k < 4;k++){
            int r = i + delRow[k],c = j + delCol[k];
                ans = max(ans,dfs(r,c,matrix,dp,m,n,delRow,delCol,matrix[i][j]));
        }
        // vis[i][j] = false;
        return dp[i][j] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = INT_MIN;
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1 };
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans = max(ans,dfs(i,j,matrix,dp,m,n,delRow,delCol,-1));
            }
        }
        return ans;
    }
};
int main(){
	int m,n;cin >> m >> n;
	vector<vector<int>> matrix(m,vector<int>(n));
	for(auto &i : matrix) for(auto &j : i) cin >> j;
	Solution s;
	cout << s.longestIncreasingPath(matrix);
	return 0;
}
