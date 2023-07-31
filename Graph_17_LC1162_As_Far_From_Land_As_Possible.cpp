#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1) q.push({i,j});
                else count++;
            }
        }
        if(count == 0) return -1;
        int ans = -1;
        int delRow[] = { -1,0,+1,0 };
        int delCol[] = { 0,+1,0,-1 };
        while(!q.empty()){
            int t = q.size();
            ans++;
            while(t--){
                int r = q.front().first,c = q.front().second;
                q.pop();
                for(int i = 0;i < 4;i++){
                    int row = r + delRow[i];
                    int col = c + delCol[i];
                    if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0){
                        grid[row][col] = -1;
                        q.push({row,col});
                    }
                }
            }
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
    cout << s.maxDistance(grid);
    return 0;
}