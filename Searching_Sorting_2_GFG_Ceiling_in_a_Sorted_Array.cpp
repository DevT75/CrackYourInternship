#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int ceiling(vector<int>&nums,int x){
		int i = lower_bound(nums.begin(), nums.end(),x) - nums.begin();
		if(i == nums.size()) return -1;
		return nums[i];
	}
};
int main(){
	int n,x;
	cin >> n >> x;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;
	Solution s;
	cout << s.ceiling(nums,x);
	return 0;
}
