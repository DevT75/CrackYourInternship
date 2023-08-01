/*
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            while(!stk.empty() && k - stk.size() <= n-i-1 && nums[i] < stk.back()) stk.pop_back();
            if(stk.size() < k) stk.push_back(nums[i]);
        }
        return stk;
    }
};
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0;i < n;i++) cin >> nums[i];
	Solution s;
	auto ans = s.mostCompetitive(nums,k);
	for(auto i : ans) cout << i << " ";
	return 0;
}