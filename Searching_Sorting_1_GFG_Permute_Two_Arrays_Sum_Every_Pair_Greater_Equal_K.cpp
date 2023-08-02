#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution{
public:
	bool isPossible(vector<int>&nums1,vector<int>&nums2,int k){
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end(),greater<int>());
		int n = min(nums1.size(),nums2.size());
		for(int i = n;i < n;i++){
			if(nums1[i] + nums2[i] < k) return false;
		}
		return true;
	}
};
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> nums1(n),nums2(n);
	for(auto &i : nums1) cin >> i;
	for(auto &i : nums2) cin >> i;
	Solution s;
	cout << (s.isPossible(nums1,nums2,k) ? "yes" : "no");
}