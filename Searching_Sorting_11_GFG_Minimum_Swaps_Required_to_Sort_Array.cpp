#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
class Solution{
public:
	void swapA(vector<int>&nums,int i,int j){
		swap(nums[i],nums[j]);
	}
	int minSwaps(vector<int>&nums){
		int n = nums.size();
		vector<int> temp(nums);
		map<int,int> m;
		for(int i = 0;i < n;i++) m[nums[i]] = i;
		sort(temp.begin(),temp.end());
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(nums[i] != temp[i]){
				ans++;
				int pre = nums[i];
				swapA(nums,i,m[temp[i]]);
				m[pre] = m[temp[i]];
				m[temp[i]] = i;
			}
		}
		return ans;
	}
};
int main(){
	int n;cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;
	Solution s;
	cout << s.minSwaps(nums);
	return 0;
}