#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp,0,sizeof dp);
        for(int i = 0;i < n;i++){
            if(i == 0){
                dp[i] = 1;
                continue;
            }
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            if(dp[i] == 0) dp[i] = 1;
        }
        int ans = *max_element(dp,dp + n);
        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    cout << s.lengthOfLIS(nums);
    return 0;
}