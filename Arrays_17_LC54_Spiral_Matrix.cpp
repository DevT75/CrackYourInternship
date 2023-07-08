#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int count = 0;
        int t = 0,l = 0,r = m - 1,b = n - 1;
        while(t <= b && l <= r && count < n*m){
            if(count < n*m)for(int i = l;i <= r;i++) {
                ans.emplace_back(matrix[t][i]);
                count++;
            }
            t++;
            if(count < n*m)for(int i = t;i <= b;i++) {
                ans.emplace_back(matrix[i][r]);
                count++;
            }
            r--;
            if(count < n*m)for(int i = r;i >= l;i--) {
                ans.emplace_back(matrix[b][i]);
                count++;
            }
            b--;
            if(count < n*m)for(int i = b;i >= t;i--) {
                ans.emplace_back(matrix[i][l]);
                count++;
            }
            l++;
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> matrix[i][j];
        }
    }
    Solution s;
    vector<int> spiral = s.spiralOrder(matrix);
    for(auto i : spiral) cout << i << " ";
    return 0;
}