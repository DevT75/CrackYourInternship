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
    int merge(vector<int>&nums,int low,int mid,int high){
        vector<int> temp(high-low+1);
        int cnt = 0;
        int j = mid + 1;
        for(int i = low;i <= mid;i++){
            while(j <= high && nums[i] > 2*(long)nums[j]) j++;
            cnt += (j-mid-1);
        }
        int i = low,idx = 0;j = mid + 1;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]) temp[idx++] = nums[i++];
            else{
                temp[idx++] = nums[j++];
            }
        }
        while(i <= mid) temp[idx++] = nums[i++];
        while(j <= high) temp[idx++] = nums[j++];
        for(int k = low;k <= high;k++) nums[k] = temp[k-low];
        return cnt;
    }
    int mergeSort(vector<int>&nums,int low,int high){
        if(low >= high) return 0;
        int cnt = 0;
        int mid = low + (high - low)/2;
        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        cnt += merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums){
        int count = mergeSort(nums,0,nums.size()-1);
        return count;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    cout << s.reversePairs(nums);
    return 0;
}