#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class cmp{
public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = INT_MIN;
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i = 0;i < n;i++){
            while((!pq.empty()) && (points[i][0]-pq.top().second > k)) pq.pop();
            if(!pq.empty()) ans = max(ans,points[i][0]+points[i][1]+pq.top().first);
            pq.push({ points[i][1]-points[i][0],points[i][0] });
        }
        return ans;
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i = 0;i < n;i++) cin >> points[i][0] >> points[i][1];
    Solution s;
    cout << s.findMaxValueOfEquation(points,k);
    return 0;
}