#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// class cmp{
// public:
//     bool operator()(vector<int>&a,vector<int>&b){
//         return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
//         for(auto i : points){
//             pq.push(i);
//         }
//         vector<vector<int>> ans;
//         while(k--){
//             auto temp = pq.top();
//             pq.pop();
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    }
    // I learned something new in this question
    // that there is a function in STL called nth_element which
    // for a index set it such that the element before are lower than it
    // and the element after are at greater
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        nth_element(points.begin(),points.begin()+k-1,points.end(),cmp);
        return vector<vector<int>> (points.begin(),points.begin()+k);
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> points;
    for(int i = 0;i < n;i++){
        int a,b;
        cin >> a >> b;
        points.push_back({ a,b });   
    }
    Solution s;
    vector<vector<int>> ans = s.kClosest(points,k);
    for(auto i : ans){
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}