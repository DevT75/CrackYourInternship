#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
	int solve(int m,vector<int> &nums){
		stable_sort(nums.begin(),nums.end());
		int i = 0,j = 0,ans = INT_MAX;
		while(j < nums.size()){
			if(j - i + 1 < m) j++;
			else if(j - i + 1 == m){
				ans = min(ans,nums[j]-nums[i]);
				i++;j++;
			}
		}
		return ans;
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	cout << s.solve(m,nums) << " ";
}