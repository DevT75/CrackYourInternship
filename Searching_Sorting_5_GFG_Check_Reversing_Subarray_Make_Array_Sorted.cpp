#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	bool isPossible(vector<int>&nums){
		int n = nums.size();
		int i = 0,j = n - 1;
		while(i + 1 < n){
			if(nums[i + 1] < nums[i]) break;
			i++;
		}
		while(j > 0){
			if(nums[j - 1] > nums[j]) break;
			j--;
		}
		for(int k = i;k < j;k++){
			if(nums[k] < nums[k + 1]) return false;
		}
		return true;
	}
};
int main(){
	int n;cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;
	Solution s;
	cout << (s.isPossible(nums) ? "yes" : "no");
	return 0;
}