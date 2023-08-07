#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<char>>& board,int r,int c,char op){
        for(int i = 0;i < 9;i++) if(board[r][i] == op) return false;
        for(int i = 0;i < 9;i++) if(board[i][c] == op) return false;
        for(int i = 0;i < 9;i++) if(board[3*(r/3)+i/3][3*(c/3)+i%3] == op) return false;
        return true; 
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    for(char op = '1';op <= '9';op++){
                        if(isValid(board,i,j,op)){
                            board[i][j] = op;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        
        solve(board);
    }
};

int main(){
    vector<vector<char>> board(9,vector<char>(9));
    for(int i = 0;i < 9;i++) for(int j = 0;j < 9;j++) cin >> board[i][j];
    Solution s;
    s.solveSudoku(board);
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++) cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}