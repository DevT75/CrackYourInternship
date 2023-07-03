#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(vector<int>&nums,int target){
		int n = nums.size();
		int start = 0,end = n - 1,idx = -1;
		while(start <= end){
			int mid = start + (end - start)/2;
			if(nums[mid] == target){
				idx = mid;
				break;
			}
			else if(nums[start] <= nums[mid]){
				if(target >= nums[start] && target <= nums[mid]) end = mid -1;
				else start = mid + 1;
			}
			else if(nums[mid] <= nums[end]){
				if(target >= nums[mid] && target <= nums[end]) start = mid + 1;
				else end = mid - 1;
			}
		}
		return idx;
	}
};

int main(){
	int n,target;
	cin >> n >> target;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	int ans = s.search(nums,target);
	// Index of the target will be returned if found else -1 
	cout << ans << "\n";
	return 0;
}