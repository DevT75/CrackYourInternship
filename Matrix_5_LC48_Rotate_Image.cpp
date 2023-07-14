#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int i = 0,j = n-1;
        while(i < j){
            for(int x = 0;x < n;x++){
                swap(matrix[x][i],matrix[x][j]);
            }
            i++;j--;
        }
    }
};

int main(){
	int n;
	cin >> n;
	vector<vector<int>> matrix(n,vector<int>(n));
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> matrix[i][j];
	Solution s;
	s.rotate(matrix);
	for(auto i : matrix){
		for(auto j : i) cout << j << " ";
		cout << "\n";
	}
	return 0;
}
