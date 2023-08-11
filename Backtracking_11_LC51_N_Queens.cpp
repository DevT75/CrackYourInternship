#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i < n;i++){
            if(isValid(i,col,board,n)){
                board[i][col] = 'Q';
                solve(col + 1,ans,board,n);
                board[i][col] = '.';
            }
        }
        return;
    }
    bool isValid(int r,int c,vector<string>&board,int n){
        for(int col = 0;col < n;col++){
            if(board[r][col] == 'Q') return false;
        }
        int row = r,col = c;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;c--;
        }
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;col--;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s = "";
        for(int i = 0;i < n;i++) s.push_back('.');
        vector<string> temp(n,s);
        solve(0,ans,temp,n);
        return ans;
    }
};
int main(){
    int n;cin >> n;
    Solution s;
    auto ans = s.solveNQueens(n);
    for(auto v : ans){
        for(auto str : v){
            for(int i = 0;i < n;i++) cout << str[i] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}