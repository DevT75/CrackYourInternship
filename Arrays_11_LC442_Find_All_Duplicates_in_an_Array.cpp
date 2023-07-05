#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 1,0);
        vector<int> ans;
        for(auto i : nums){
            if(arr[i] == 1) ans.push_back(i);
            else arr[i]++;
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
	vector<int> ans = s.findDuplicates(nums);
    for(auto i : ans) cout << i << " ";
	return 0;
}
