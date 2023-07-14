#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(board);
        int delRow[] = { -1,-1,-1,0,0,+1,+1,+1 };
        int delCol[] = { 0,-1,+1,-1,+1,+1,-1,0};
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int n_count = 0;
                for(int k = 0;k < 8;k++){
                    int r = i + delRow[k];
                    int c = j + delCol[k];
                    if(r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 1) n_count++;
                }
                if(board[i][j] == 0){
                    if(n_count == 3) ans[i][j] = 1;
                    else ans[i][j] = 0;
                }
                else{
                    if(n_count == 2 || n_count == 3) ans[i][j] = 1;
                    else ans[i][j] = 0;
                }
            }
        }
        board = ans;
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> board(n,vector<int>(m));
    for(int i = 0;i < n;i++)for(int j = 0;j < m;j++) cin >> board[i][j];
    Solution s;
    s.gameOfLife(board);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}