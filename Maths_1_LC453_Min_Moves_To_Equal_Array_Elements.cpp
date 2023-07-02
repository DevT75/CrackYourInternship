#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0;i < n;i++) mini = min(mini,nums[i]);
        for(int i = 0;i < n;i++) ans += abs(nums[i]-mini);
        return ans;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;
	Solution s;
	int ans = s.minMoves(nums);

	cout << ans << "\n"; 

	return 0;
}