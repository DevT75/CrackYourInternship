#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
class cmp{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,cmp> pq;
        unordered_map<int,int> m;
        for(auto i : nums) m[i]++;
        for(auto i : m){
            pq.push(i);
        }
        vector<int> ans;
        while(k--){
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

int main(){
    int n,k;cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    vector<int> ans = s.topKFrequent(nums,k);
    for(auto i : ans) cout << i << "\n";
    return 0;
}