#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first < b.first;
    }

    // Returns the index of the numbers that add upto target
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<pair<int,int>> v(nums.size());
        for(int i = 0;i < nums.size();i++){
            v[i] = { nums[i],i };
        }
        sort(v.begin(),v.end(),cmp);
        int start = 0,end = nums.size()-1;
        while(start < end){
            if(v[start].first + v[end].first == target){
                ans.push_back(v[start].second);
                ans.push_back(v[end].second); 
                break;
            }
            else if(v[start].first + v[end].first < target) start++;
            else end--;
        }
        return ans;
    }
};

int main(){
	int n,target;
	cin >> n >> target;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	vector<int> ans = s.twoSum(nums,target);
	for(auto i : ans) cout << i << " ";
	return 0;
}