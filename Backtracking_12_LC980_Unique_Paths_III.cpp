#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int cnt){
        if(i >= grid.size() || j >= grid[0].size() ||  i < 0 || j < 0 || grid[i][j] == -1) return 0;
        if(grid[i][j] == 2){
            if(cnt == -1) return 1;
            // why -1 because when we reach the final cell we are covering onr extra cell than the cnt
            return 0;
        }
        grid[i][j] = -1;
        cnt--;
        int ans = solve(i + 1,j,grid,cnt) + solve(i - 1,j,grid,cnt) + 
                    solve(i,j + 1 ,grid,cnt) + solve(i,j - 1,grid,cnt);
        grid[i][j] = 0;
        cnt++;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> start = {-1,-1};
        int cnt = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 0) cnt++;
                else if(grid[i][j] == 1){
                    start = { i,j };
                }
            }
        }
        return solve(start.first,start.second,grid,cnt);
    }
};
int main(){
	int m,n;cin >> m >> n;
	vector<vector<int>> grid(m,vector<int>(n));
	for(auto &i : grid) for(auto &j : i) cin >> j;
	Solution s;
	cout << s.uniquePathsIII(grid);
	return 0;
}