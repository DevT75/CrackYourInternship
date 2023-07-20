#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <cstring>
#include <utility>
using namespace std;

class Solution{
private:
	void dfs(int r,int c,vector<vector<char>>& mat,vector<vector<bool>>&vis,int n,int m){
		vis[r][c] = true;
		for(int i = -1;i <= 1;i++){
			for(int j = -1;j <= 1;j++){
				if(i == 0 && j == 0) continue;
				else{
					int row = r + i,col = c + j;
					if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && mat[row][col] == 'O'){
						dfs(row,col,mat,vis,n,m);
					}
				}
			}
		}
	}
public:
	void replaceOX(vector<vector<char>>& mat){
		int n = mat.size();
		int m = mat[0].size();
		vector<pair<int,int>> ez;
		vector<vector<bool>> vis(n,vector<bool>(m,false));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++) 
				if((i == 0 || j == 0 || i == n-1 || j == m-1) 
					&& mat[i][j] == 'O') ez.push_back({i,j});
		for(int i = 0;i < ez.size();i++){
			auto temp = ez[i];
			if(!vis[temp.first][temp.second]) dfs(temp.first,temp.second,mat,vis,n,m);
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
			}
		}
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> mat(n,vector<char>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++) cin >> mat[i][j];
	Solution s;
	s.replaceOX(mat);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cout << mat[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
