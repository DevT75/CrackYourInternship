#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> colZero(m + 1,1);
        vector<int> rowZero(n + 1,1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    colZero[j] = 0;
                    rowZero[i] = 0;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(colZero[j] == 0 || rowZero[i] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> matrix(n,vector<int>(m));
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> matrix[i][j];
	Solution s;
	s.setZeroes(matrix);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) cout << matrix[i][j] << " ";
        cout << "\n";
	}
	return 0;
}