#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int ans = *max_element(nums.begin(),nums.end());
    //     int currMax = 1,currMin = 1;
    //     for(auto i : nums){
    //         int temp1 = currMax*i,temp2 = currMin*i;
    //         currMax = max(temp1,max(temp2,i));
    //         currMin = min(temp1,min(temp2,i));
    //         ans = max(ans,currMax);
    //     }
    //     return ans;
    // }
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int pre = 1,suf = 1;
        for(int i = 0;i < n;i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= nums[i];
            suf *= nums[n-i-1];
            ans = max(ans,max(pre,suf));
        }
        return ans;
    }
};

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++) cin >> arr[i];
	Solution s;
	cout << s.maxProduct(arr);
}
