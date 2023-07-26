#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <climits>
using namespace std;
class Solution {
public:
    void merge(vector<pair<int,int>>&nums,vector<int>&ans,int low,int mid,int high){
        vector<pair<int,int>> temp(high-low+1);
        int i = low,j = mid + 1,idx=0;
        while(i <= mid && j <= high){
            if(nums[i].first <= nums[j].first) temp[idx++] = nums[j++];
            else{
                ans[nums[i].second] += (high - j + 1);
                temp[idx++] = nums[i++];
            }
        }
        while(i <= mid) temp[idx++] = nums[i++];
        while(j <= high) temp[idx++] = nums[j++];
        for(int k = low;k <= high;k++) nums[k] = temp[k-low];
    }
    void mergeSort(vector<pair<int,int>>&nums,vector<int>&ans,int low,int high){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums,ans,low,mid);
        mergeSort(nums,ans,mid+1,high);
        merge(nums,ans,low,mid,high);
    }
    vector<int> countSmaller(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>> temp(n);
        for(int i = 0;i < n;i++) temp[i] = {nums[i],i};
        vector<int> ans(n);
        mergeSort(temp,ans,0,n-1);
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