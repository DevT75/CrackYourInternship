#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int n,int m,
    queue<pair<int,int>>&q){
        vis[i][j] = true;
        grid[i][j] = 2;
        q.push({i,j});
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1 };
        for(int k = 0;k < 4;k++){
            int r = i + delRow[k];
            int c = j + delCol[k];
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1){
                dfs(r,c,grid,vis,n,m,q);
            }
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int x = -1,y = -1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1 || y != -1) break;
        }
        dfs(x,y,grid,vis,n,m,q);
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1 };
        while(!q.empty()){
            int t = q.size();
            while(t--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k = 0;k < 4;k++){
                    int row = r + delRow[k],col = c + delCol[k];
                    if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col]){
                        if(grid[row][col] == 1) return ans;
                        vis[row][col] = true;
                        q.push({row,col});
                        }
                    }
            }
            ans++;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0;i < n;i++) for(auto &j : grid[i]) cin >> j;
    Solution s;
    cout << s.shortestBridge(grid);
    return 0;
}