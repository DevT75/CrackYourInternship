#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem(k);
        for(int i = 1;i < n;i++) nums[i] += nums[i - 1];
        int count = 0;
        for(int i = 0;i < n;i++){
            int t = nums[i] % k;
            if(t < 0) t += k;
            count += rem[t];
            rem[t]++;
        }
        count += rem[0];
        return count;
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums) cin >> i;
    Solution s;
    cout << s.subarraysDivByK(nums,k);
    return 0;
}