#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <climits>
using namespace std;

class cmp{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i = 0;i < n;i++){
            pq.push({ nums[i],i });
        }
        while(!pq.empty()){
            auto temp = pq.top();pq.pop();
            cout << temp.first << " " << temp.second << "\n";
        }
        int count = 0;
        int lastIdx = INT_MAX;
        int lastVal = INT_MAX;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(temp.second > lastIdx){
                int sum = 0; 
                int i = temp.second;
                if(i + 1 < n && nums[i + 1] < nums[i]) sum = 1;
				i++;
				while(i < n) {
					sum += ans[i];
					i++;
				}
				ans[temp.second] = sum;
            }
            else if(temp.first == lastVal){
            	ans[temp.second] = 0;
            }
            else{
            	ans[temp.second] = count;
            	count++;
            }
            lastIdx = temp.second;
            lastVal = temp.first;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    vector<int> ans = s.countSmaller(nums);
    for(auto i : ans) cout << i << " ";
    return 0;
}