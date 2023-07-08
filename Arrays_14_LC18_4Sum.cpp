#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(int start,vector<int>&nums,long long target){
        vector<vector<int>> ans;
        int low = start,high = nums.size() - 1;
        while(low < high){
            long long sum = nums[low] + nums[high];
            if(sum < target || (low > start && nums[low] == nums[low - 1])) low++;
            else if(sum > target || (high < nums.size()-1 && nums[high] == nums[high + 1])) high--;
            else{
                ans.push_back({ nums[low],nums[high] });
                low++;
                high--;
            }
        }
        return ans;
    }
    vector<vector<int>> kSum(vector<int>& nums,int start,long long target,int k){
        vector<vector<int>> res;
        if(start == nums.size()) return res;
        long long avg = target/k;
        if(nums[start] > avg || nums.back() < avg) return res;
        if(k == 2) return twoSum(start,nums,target);

        for(int i = start;i < nums.size();i++){
            if(i == start || nums[i-1] != nums[i]){
                for(vector<int>& j : kSum(nums,i + 1,static_cast<long long> (target)-nums[i],k-1)){
                    res.push_back({ nums[i] });
                    res.back().insert(res.back().end(),j.begin(),j.end());
                }
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,0,target,4);
    }
};

int main(){
    int n,target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];

    Solution s;
    vector<vector<int>> ans = s.fourSum(nums,target);
    for(auto &i : ans){
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}