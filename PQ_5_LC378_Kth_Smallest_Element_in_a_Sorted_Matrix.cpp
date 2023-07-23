#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                pq.push(matrix[i][j]);
            }
        }
        int ans;
        while(!pq.empty() && k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> matrix[i][j];
        }
    }
    Solution s;
    cout << s.kthSmallest(matrix,k);
    return 0;
}