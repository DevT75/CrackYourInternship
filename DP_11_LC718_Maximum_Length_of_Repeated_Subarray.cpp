#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        for(int i = 0;i < n + 1;i++){
            for(int j = 0;j < m + 1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n),nums2(m);
    for(auto &i : nums1) cin >> i;
    for(auto &i : nums2) cin >> i;
    Solution s;
    cout << s.findLength(nums1,nums2);
    return 0;
}