#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	bool isPossible(vector<int>&nums,int maxi,int k){
		int subarr = 1;
		int sum = 0;
		for(auto i : nums){
			sum += i;
			if(sum > maxi){
				subarr++;
				sum = i;
			}
			if(subarr > k) return false;
		}
		return true;
	}
	int splitArray(vector<int>& nums,int k){
		int start = INT_MIN;
		int end = 0;
		int ans = -1;
		for(auto i : nums){
			start = max(start,i);
			end += i;
		}
		while(start <= end){
			int mid = start + (end - start)/2;
			if(isPossible(nums,mid,k) == true){
				ans = mid;
				end = mid - 1;
			}
			else start = mid + 1;
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
	cout << s.splitArray(nums,k) << "\n";
	return 0;
}