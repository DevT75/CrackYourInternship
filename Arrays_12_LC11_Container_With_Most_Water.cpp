#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maxArea(vector<int>&height){
		int ans = INT_MIN;
		int start = 0,end = height.size() - 1;
		while(start <= end) {
			int width = end - start;
		    ans = max(ans,min(height[start],height[end])*width);
		    if(height[start] <= height[end]) start++;
		    else end--;
		}
		return ans;
	}
};
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;

	Solution s;
	cout << s.maxArea(nums) << "\n";
	return 0;
}