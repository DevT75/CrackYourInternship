#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(k == 1) return nums;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        int i = 0,j = 0,n = nums.size();
        vector<int> ans;
        while(j < n){
            pq.push({nums[j],j});
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k){
                while(!pq.empty() && pq.top().second <= (j - k)) pq.pop();
                if(pq.empty()) return ans;
                ans.push_back(pq.top().first);
                i++;
                j++;
            }
        }
        return ans;
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    vector<int> ans = s.maxSlidingWindow(nums,k);
    for(auto i : ans) cout << i << " ";
    return 0;
}