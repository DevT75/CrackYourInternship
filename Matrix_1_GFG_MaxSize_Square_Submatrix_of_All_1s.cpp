#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	void printSubMatrix(vector<vector<int>>&matrix){
		int n = matrix.size(),m = matrix[0].size();
		int dp[n][m];
		int maxi = INT_MIN;
		int pos[2] = { 0, 0 };
		for(int i = 0,j = 0;i < n,j < m;i++,j++){
			dp[i][0] = matrix[i][0];
			dp[0][j] = matrix[0][j];
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				if(matrix[i][j] == 1){
					dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
					if(maxi <= dp[i][j]){
						maxi = dp[i][j];
						pos[0] = i;
						pos[1] = j;
					}
				}
				else dp[i][j] = 0;
			}
		}
		for(int i = pos[0]-maxi+1;i <= pos[0];i++){
			for(int j = pos[1]-maxi+1;j <= pos[1];j++) cout << matrix[i][j] << " ";
			cout << "\n";
		}
		cout << pos[0] << " " << pos[1] << "\n";
	}
};
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> matrix(n,vector<int>(m));
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> matrix[i][j];

	Solution s;
	s.printSubMatrix(matrix);

	return 0;
}