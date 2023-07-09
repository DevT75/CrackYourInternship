#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int x,int y,int m,int n){
        queue<pair<int,int>> q;
        q.push({ x, y });
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int i = temp.first,j = temp.second;
            vis[i][j] = true;
            int right = j + 1 < n ? j + 1 : j;
            int left = j - 1 >= 0 ? j - 1 : j;
            int up = i - 1 >= 0 ? i - 1 : i;
            int down = i  + 1 < m ? i + 1 : i;
            if(!vis[i][right] && grid[i][right] != '0'){
                vis[i][right] = true;
                q.push({ i,right });
            }
            if(!vis[i][left] && grid[i][left] != '0'){
                vis[i][left] = true;
                q.push({ i,left });
            }
            if(!vis[up][j] && grid[up][j] != '0'){
                vis[up][j] = true;
                q.push({ up, j });
            }
            if(!vis[down][j] && grid[down][j] != '0'){
                vis[down][j] = true;
                q.push({ down, j });
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid,vis,i,j,m,n);
                }
            }
        }
        return count;
    }
};

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<char>> v (m,vector<char> (n));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++) cin >> v[i][j];
    }
    Solution s;
    cout << s.numIslands(v) << "\n";
    return 0;
}