#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
        vector<vector<int>> vis(N,vector<int>(N,false));
        queue<pair<pair<int,int>,int>> q;
        q.push({{KnightPos[0]-1,KnightPos[1]-1},0});
        int delRow[] = {-2,-2,-1,-1,+1,+1,+2,+2};
        int delCol[] = {-1,+1,-2,+2,-2,+2,-1,+1};
        vis[KnightPos[0]-1][KnightPos[1]-1] = true;
        int ans = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
           // cout << row << " " << col << " " << steps << "\n";
            q.pop();
            if(row == TargetPos[0]-1 && col == TargetPos[1]-1){
                ans = steps;
                break;
            }
            for(int i = 0;i < 8;i++){
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(r >= 0 && r < N && c >= 0 && c < N && !vis[r][c]){
                    vis[r][c] = true;
                    q.push({ {r, c}, steps + 1 });
                }
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> kp(2),tp(2);
    cin >> kp[0] >> kp[1];
    cin >> tp[0] >> tp[1];
    Solution s;
    cout << s.minStepToReachTarget(kp,tp,n);

}