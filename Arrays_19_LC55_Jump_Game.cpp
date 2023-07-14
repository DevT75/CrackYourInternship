#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //    bool ans = false;
    //    int n = nums.size();
    //    if(n == 1) return true;
    //    if(nums[0] == 0) return false;
    //    long temp = n-1;
    //    int start = 0,end = n-2;
    //    for(int i = n-2;i >= 0;i--){
    //        if(nums[i] >= temp - i){
    //             ans = true;
    //             temp = i;
    //        }
    //        else ans = false;
    //    }
    //     return ans;
    // }
	bool canJump(vector<int>& nums) {
	    int temp = 0;
	    int n = nums.size();
	    for(int i = 0;i <= temp;i++){
	        temp = max(temp,nums[i]+i);
	        if(temp >= n - 1) return true;
	    }
	    return false;
    }
};
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &i : nums) cin >> i;
	Solution s;
	cout << (s.canJump(nums) ? "true" : "false");
	return 0;
}