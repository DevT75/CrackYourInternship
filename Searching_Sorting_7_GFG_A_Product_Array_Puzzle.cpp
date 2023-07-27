#include <iostream>
#include <vector>
using namespace std;
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> pre(n,1),post(n,1);
        vector<long long int> ans(n);
        for(int i = 1,j = n - 2;i < n,j >= 0;i++,j--){
            pre[i] = pre[i-1]*nums[i-1];
            post[j] = post[j+1]*nums[j+1];
        }
        for(int i = 0;i < n;i++) ans[i] = pre[i]*post[i];
        return ans;
    }
};
int main(){
  int n;
  cin >> n;
  vector<long long int> nums(n);
  for(auto &i : nums) cin >> i;
  Solution s;
  auto ans = s.productExceptSelf(nums,n);
  for(auto i : ans) cout << i << " ";
  return 0;
}