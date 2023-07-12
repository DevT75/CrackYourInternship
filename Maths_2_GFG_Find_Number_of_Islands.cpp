#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
	void dfs(vector<vector<int>>&adj,int r,int c,vector<vector<bool>>&vis,int n,int m){
		vis[r][c] = true;
		for(int i = -1;i <= 1;i++){
			for(int j = -1;j <= 1;j++){
				int row = r + i;
				int col = c + j;
				if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col]){
					dfs(adj,row,col,vis,n,m);
				}
			}
		}
	}
	int findNumber(vector<vector<int>>&adj,int n,int m){
		vector<vector<bool>>vis(n,vector<bool>(m,false));
		int count = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!vis[i][j]) {
					count++;
					dfs(adj,i,j,vis,n,m);
				}
			}
		}
		return count;
	}
};
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n,vector<int>(m));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cin >> adj[i][j];
	}
	Solution s;
	cout << s.findNumber(adj,n,m);
}
