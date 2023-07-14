#include <iostream>
#include <vector>
using namespace std;
class Solution {
    private:
        bool dfs(string&word,int idx,int i,int j,vector<vector<char>>& board,vector<vector<bool>>& vis,int n,int m){
            if(idx == word.length() - 1){
                if(board[i][j] == word[idx]) return true;
                else return false;
            }
            // cout << board[i][j] << " ";
            vis[i][j] = true;
            int delRow[] = { -1,0,+1,0 };
            int delCol[] = { 0,+1,0,-1 };
            for(int x = 0;x < 4;x++){
                int r = i + delRow[x];
                int c = j + delCol[x];
                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && word[idx + 1] == board[r][c]
                    && dfs(word,idx + 1,r,c,board,vis,n,m)){
                    return true;
                }
            }
            vis[i][j] = false;
            return false;
        }
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int n = board.size();
            int m = board[0].size();
            // vector<pair<int,int>> c;
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++){
                    if(board[i][j] == word[0] && dfs(word,0,i,j,board,vis,n,m)) return true;
                }
            }
            cout << "\n";
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++) cout << vis[i][j] << " ";
                cout << "\n";
            }
            return false;
        }
};


int main(){
    int n,m;
    string word;
    cin >> n >> m >> word;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i = 0;i < n;i++)for(int j = 0;j < m;j++) cin >> board[i][j];
    Solution s;
    cout << (s.exist(board,word) ? "true" : "false");
    return 0;
}